#include <iostream>
#include <future>
#include <string>
#include <thread>
#include <chrono>


int find_the_answer_ltuae() 
{
    auto amount_milisecond = std::chrono::milliseconds(2000);

    std::this_thread::sleep_for(amount_milisecond);
    return 10;
}

void do_other_stuff() {
    std::cout << "Hello world" << std::endl;
}


int main() {
    std::future<int> the_answer = std::async(std::launch::deferred, find_the_answer_ltuae);


    std::shared_future<int> the_shared_ans_1 = std::async(std::launch::deferred, find_the_answer_ltuae);
    std::shared_future<int> the_shared_ans_2(the_shared_ans_1);




    do_other_stuff();
    std::cout << "Answer equals: " << the_answer.get() << std::endl;

    std::cout << "Anser equals shared 1: " << the_shared_ans_1.get() << std::endl;

    std::cout << "Anser equals shared 2: " << the_shared_ans_2.get() << std::endl;


    return 0;
}