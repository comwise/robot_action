#include "python_action.h"
#include <stdexcept>

PythonAction::PythonAction(const std::string& modulePath) {
    py::module sys = py::module::import("sys");
    sys.attr("path").append(modulePath);
    
    py::module mod = py::module::import("robot_action");
    actionObj_ = mod.attr("RobotAction")();
}

nlohmann::json PythonAction::getParamSchema() const {
    auto schema = actionObj_.attr("get_param_schema")().cast<std::string>();
    return nlohmann::json::parse(schema);
}

bool PythonAction::execute(const nlohmann::json& params) {
    py::gil_scoped_acquire acquire;
    try {
        py::dict pyParams = py::module::import("json").attr("loads")(params.dump());
        return actionObj_.attr("execute")(pyParams).cast<bool>();
    } catch (const py::error_already_set& e) {
        throw std::runtime_error(e.what());
    }
}