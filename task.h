#ifndef TASK_H
#define TASK_H

#include <functional>
#include <future>

struct Task {
    int priority;
    std::function<void()> func;

    // Priority queue: higher priority executes first
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

#endif
