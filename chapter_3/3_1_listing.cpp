#include <list>
#include <mutex>
#include <algorithm>


std::list<int> some_list;
std::mutex some_mutex;


void add_to_list(int new_value) 
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}

auto list_contains(int value_to_find) 
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) 
        != some_list.end();
}
