#ifndef __COMWISE__ROBOT_ACTION__ACTION__H__
#define __COMWISE__ROBOT_ACTION__ACTION__H__

#include <string>
#include <map>
#include <future>
#include <memory>
#include <nlohmann/json.hpp>

enum class SafetyLevel {
    EmergencyStop,
    ProtectiveStop,
    ReducedSpeed,
    Standard
};

class Action {
public:
    virtual ~Action() = default;
    
    virtual nlohmann::json getParamSchema() const = 0;
    virtual SafetyLevel getSafetyLevel() const { return SafetyLevel::Standard; }
    
    virtual bool execute(const nlohmann::json& params) = 0;
    virtual std::future<bool> executeAsync(const nlohmann::json& params) {
        return std::async(std::launch::async, [this, params] {
            return execute(params);
        });
    }
};

using ActionPtr = std::shared_ptr<Action>;

#endif // __COMWISE__ROBOT_ACTION__ACTION__H__
