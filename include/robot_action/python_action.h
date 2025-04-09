#ifndef __COMWISE__ROBOT_ACTION__PYTHON_ACTION__H__
#define __COMWISE__ROBOT_ACTION__PYTHON_ACTION__H__

#include <string>
#include <pybind11/embed.h>
#include "Action.h"

namespace py = pybind11;

class PythonAction : public Action {
public:
    PythonAction(const std::string& modulePath);
    nlohmann::json getParamSchema() const override;
    bool execute(const nlohmann::json& params) override;

private:
    py::module module_;
    py::object actionObj_;
};

#endif // __COMWISE__ROBOT_ACTION__PYTHON_ACTION__H__
