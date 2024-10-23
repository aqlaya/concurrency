#pragma once

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <utility>

class packet
{
private:
    std::map<std::string, std::string> _inf_packet;
    std::string _data;
public:
    packet(const std::string& data, const std::map<std::string, std::string> inf_packet) noexcept
        : _inf_packet(inf_packet)
        , _data(data)
    {

    }
    packet(const packet& instance) = delete;
    packet& operator=(const packet& instance) = delete;

    packet(packet&& instance) = default;
    packet& operator=(packet&& instance) = default;

    auto get_data_packet()
        -> decltype(this->_data)
    {
        return this->_data; 
    }


    friend auto operator<<(std::ostream& stream, const packet& obj)
        -> decltype(stream)
    {
        stream << obj._data;  

        return stream;
    }
};

