#include "threadpool.h"

#include <QDebug>

ThreadPool::ThreadPool(size_t numThreads): stop(false) {
    for(size_t i = 0; i < numThreads; ++i){
        workers.emplace_back(&ThreadPool::worker, this);
    }
}

ThreadPool::~ThreadPool() {
    //qDebug() << "ThreadPool Deconstructor called!!";
    stop = true;
    condition.notify_all();
    for (std::thread &worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

void ThreadPool::addTask(std::function<void()> task) {
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(task);
    }
    condition.notify_one();
}

void ThreadPool::worker() {
    while (!stop) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] { return !tasks.empty() || stop; });

            if (stop && tasks.empty()) return;

            task = tasks.front();
            tasks.pop();
        }

        task();
    }
}
