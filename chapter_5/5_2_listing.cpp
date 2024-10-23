#include <vector>
#include <atomic>
#include <iostream>
#include <thread>

std::vector<int> data;
std::atomic<bool> data_ready(false);


void reader_thread()
{
    while (!data_ready.load())
    {
        std::this_thread::sleep(std::milliseconds(1));
    }

    std::cout << "Answer=" << data[0] << '\n';
}

void writer_thread()
{
    data.push_back(42);
    data_ready=true;
}