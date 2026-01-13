#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;

int amount = 0;
bool t1_turn = true;

void add(int id)
{
    for (int i = 0; i < 3; ++i)
    {
        std::unique_lock<std::mutex> lock(m);

        cv.wait(lock, [&] {
            return (id == 1 && t1_turn) || (id == 2 && !t1_turn);
        });

        ++amount;
        std::cout << "thread t" << id << " incremented amount\n";

        t1_turn = !t1_turn;
        cv.notify_one();
    }
}

int main()
{
    std::thread t1(add, 1);
    std::thread t2(add, 2);

    t1.join();
    t2.join();
}

