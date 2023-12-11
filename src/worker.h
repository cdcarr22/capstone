#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//Help from Udacity GPT
class Worker {
private:
    std::mutex mtx;
    std::condition_variable cv;
    bool condition = false;

public:
    void doWork() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return condition; }); // Wait until the condition is true

        // Do some work
        std::cout << "Worker thread is doing some work" << std::endl;
    }

    void notify() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            condition = true;
        }
        cv.notify_one(); // Notify the waiting thread that the condition is met
    }
};