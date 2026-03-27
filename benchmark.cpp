#include "thread_pool.h"
#include <iostream>
#include <chrono>

int main() {
    ThreadPool pool(4);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 10000; i++) {
        pool.enqueue({
            i,
            []() {}
        });
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Scheduled 10k tasks in "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    return 0;
}
