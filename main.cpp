#include "thread_pool.h"
#include <iostream>
#include <chrono>

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 10; i++) {
        pool.enqueue({
            i, // priority
            [i]() {
                std::cout << "Executing Task " << i << std::endl;
            }
        });
    }

    return 0;
}
