#include "packet.hpp"
#include "receiver.hpp"
#include "connection.hpp"
#include "sender.hpp"

#include <string>
#include <memory>
#include <future>
#include <thread>
#include <fstream>


int main(int args, char** argv)
{
    std::vector<connection> connections(100, connection());
    std::vector<sender> senders(5, sender());

    std::size_t i = 0;
    while (true) {
        if (connections[i].has_outcoming_data_packet())
        {
            promise<bool>
            for (size_t)
        }

        i += 1;
        i %= 100;

    }

    return 0;
}