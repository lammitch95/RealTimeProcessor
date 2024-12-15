#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <QObject>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadPool{

public:
    explicit ThreadPool(size_t numThreads);
    ~ThreadPool();

    void addTask(std::function<void()> task);

private:

    void worker();
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

#endif // THREADPOOL_H
