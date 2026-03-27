#include "thread_pool.h"

ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back([this]() {
            while (true) {
                Task task;

                {
                    std::unique_lock<std::mutex> lock(mtx);

                    cv.wait(lock, [this]() {
                        return stop || !taskQueue.empty();
                    });

                    if (stop && taskQueue.empty())
                        return;

                    task = taskQueue.top();
                    taskQueue.pop();
                }

                task.func();
            }
        });
    }
}

void ThreadPool::enqueue(Task task) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        taskQueue.push(task);
    }
    cv.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }

    cv.notify_all();

    for (auto &worker : workers)
        worker.join();
}
