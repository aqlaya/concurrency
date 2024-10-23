#include <future>
#include <memory>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>

// don't safety

class complicated_data {
    std::vector<int> data_;
public:
    complicated_data(std::vector<int>&& data)
        :  data_(data)

    {
        std::cout << "Complicated_data is created";
    }
    std::vector<int> get_data() {
        return data_;
    }
};

complicated_data get_value_for_first_thread() {
    std::cout << "first thread is launched" << std::endl;
    return complicated_data(std::vector<int>(220, 1));
}


auto output = [](const auto& vector_f) {
    std::for_each(vector_f.begin(), vector_f.end(), [](int a) {
        std::cout << a << " ";
    });
    std::cout << std::endl;
};



complicated_data get_value_for_second_thread() {
    std::cout << "second thread is launched" << std::endl;
    return complicated_data(std::vector<int>(100, 2));
}

void first_thread_(std::shared_future<complicated_data> f) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    f = std::async(get_value_for_first_thread);


    auto complicated_data_f = f.get();
    auto vector_f(std::move( complicated_data_f.get_data() ));

    output(vector_f);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    complicated_data_f = f.get();
    vector_f = std::move(complicated_data_f.get_data());
    output(vector_f);

}


void second_thread_(std::shared_future<complicated_data> f) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    f = std::async(get_value_for_second_thread);


    auto complicated_data_f = f.get();
    auto vector_f = std::move(complicated_data_f.get_data());
    output(vector_f);
}

int main() {
    std::shared_future<complicated_data> f;
    std::thread first_thread(second_thread_, std::ref(f));
    std::thread second_thread(first_thread_, std::ref(f));

    first_thread.join();
    second_thread.join();

    return 0;
}