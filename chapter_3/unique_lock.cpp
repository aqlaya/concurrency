#include <iostream>

#include <string>
#include <thread>

#include <mutex>
#include <list>

std::mutex some_mutex;

std::list<int> element_list;

void do_something() {
    /* ... */
}

void prepare_data() {
    /* ... */
}


std::unique_lock<std::mutex> get_lock() { 
    extern std::mutex some_mutex;
    std::unique_lock<std::mutex> lk(some_mutex);
    prepare_data();
    return lk;
}


void process_data() 
{
    std::unique_lock<std::mutex> lk(get_lock());
    do_something();


    return ;
}


int main(int args, char** argv) {

    process_data();

}