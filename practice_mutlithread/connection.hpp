#pragma once

#include <iostream>
#include <future>
#include <memory>
#include <thread>

#include <fstream>

#include "packet.hpp"

extern std::size_t count;

struct connection_descriptor {
    std::string _name_connection;
    std::fstream _stream;

    void close() 
    {
        _stream.close();
    }

    friend auto& 
    operator<<(std::ostream& stream, const connection_descriptor& obj) 
    {
        stream << obj._name_connection;
        return stream;
    }


    template <typename T>
    auto operator<<(const T& obj)
        -> connection_descriptor&
    {
        this->_stream << obj;

        return *this;
    }
};

class connection 
{
public:
    connection() 
        : descriptor_({ std::to_string(count++), std::fstream("log.log")})
        , incoming_data_packet_()
        , outcoming_data_packet_() 
    {
        std::cerr << "Create connection: " << '[' << descriptor_ << ']' << '\n';
    }

    ~connection() 
    {
        descriptor_.close();
    }


    bool send_outcoming_data_packet() 
    {
        std::promise<bool> p_success;

        std::future<bool> success = p_success.get_future();
         
        return true;
    }

    bool has_incoming_data_packet() 
    {
        return static_cast<bool>(incoming_data_packet_); 
    }

    bool has_outcoming_data_packet()
    {
        return static_cast<bool>(outcoming_data_packet_);
    }




    connection(const connection& connec) = default;
    connection&  operator=(const connection& connect) = default;

private:
    connection_descriptor descriptor_;
    std::shared_ptr<packet> incoming_data_packet_; 
    std::shared_ptr<packet> outcoming_data_packet_;
};

