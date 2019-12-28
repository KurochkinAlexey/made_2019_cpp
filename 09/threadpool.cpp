#include "threadpool.h"

ThreadPool::ThreadPool(size_t poolSize): isRunning(true) {
    for(size_t i = 0; i < poolSize; i++) {
        pool.push_back(std::thread(std::bind(&ThreadPool::workOrder, this)));
    }
}


void ThreadPool::workOrder()
{
    while(isRunning) {
        std::unique_lock<std::mutex> lock(mutex);
        if(!taskQueue.empty()) {
            auto task = taskQueue.front();
            taskQueue.pop();
            lock.unlock();
            task();
        } else {
            scheduler.wait(lock);
        }
    }
}


ThreadPool::~ThreadPool() {
    isRunning = false;
    scheduler.notify_all();
    for(auto& t: pool) {
        //t.detach();
        t.join();
    }
}

