#include "scheduler.h"

void Scheduler::registerAction(const std::string& name, ActionPtr action) {
    std::lock_guard<std::mutex> lock(mutex_);
    actions_[name] = action;
}

void Scheduler::unregisterAction(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto cit = actions_.find(name);
    if (cit != actions_.end()) {
        actions_.erase(cit);
    }
}

void Scheduler::schedule(Task&& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(std::move(task));
    cv_.notify_one();
}

Scheduler::Task Scheduler::getNextTask() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]{ return !queue_.empty(); });
    
    Task task = std::move(queue_.top());
    queue_.pop();
    return task;
}