#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "task.h"
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::priority_queue<Task> taskQueue;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop;

public:
    ThreadPool(size_t threads);

    void enqueue(Task task);

    ~ThreadPool();
};

#endif
