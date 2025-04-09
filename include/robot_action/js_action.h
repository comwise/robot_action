// jsaction.h
#ifndef __COMWISE__ROBOT_ACTION__JS_ACTION__H__
#define __COMWISE__ROBOT_ACTION__JS_ACTION__H__

#include <string>
#include <sstream>
#include <iostream>
//#include <v8.h>
#include "action.h"

class JsAction : public Action {
public:
    JsAction(const std::string& scriptPath) { };
    ~JsAction() { };
    
    nlohmann::json getParamSchema() const override { return nlohmann::json(); }
    bool execute(const nlohmann::json& params) override { return false; }

private:
    //v8::Isolate* isolate_;
    //v8::Global<v8::Context> context_;
    //v8::Global<v8::Function> func_;
};

#endif // __COMWISE__ROBOT_ACTION__JS_ACTION__H__
