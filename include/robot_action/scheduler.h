
#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include "action.h"

class Scheduler {
public:
    struct Task {
        ActionPtr action;
        nlohmann::json params;
        int priority;
        std::chrono::milliseconds timeout;
        bool operator<(const Task& other) const {
            return priority < other.priority;
        }
    };

    void registerAction(const std::string& name, ActionPtr action);
    void unregisterAction(const std::string& name);

    void schedule(Task&& task);
    Task getNextTask();

private:
    std::priority_queue<Task> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    std::unordered_map<std::string, ActionPtr> actions_;
};