#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <memory>
#include <functional>


class ThreadPool
{
public:
    using TaskPtr = std::function<void()>;

    ThreadPool(size_t poolSize);
    ~ThreadPool();

    template<typename Func, typename... Args>
    auto exec(Func f, Args... args) -> std::future<decltype (f(args...))> {
        using TaskType = std::packaged_task<decltype (f(args...)) ()>;
        //std::shared_ptr<TaskType> task(new TaskType(std::bind(f, args...)));
        TaskType* task = new TaskType(std::bind(f, args...));
        auto future = task->get_future();
        std::unique_lock<std::mutex> lock(mutex);
        taskQueue.push([task](){
            (*task)();
            delete task;
            return;});

        lock.unlock();
        scheduler.notify_one();
        return future;
    }

private:
    void workOrder();


    bool isRunning;
    std::vector<std::thread> pool;
    std::queue<TaskPtr> taskQueue;
    std::mutex mutex;
    std::condition_variable scheduler;
};



#endif // THREADPOOL_H
