#pragma once

#include <string>
#include <memory>
#include <future>
#include <thread>

#include "packet.hpp"
#include  "connection.hpp"

class sender 
{
public:

    using desc = connection_descriptor;
    sender() = default;

    template <typename T>
    bool operator()(const T& data_packet, desc& descriptor) noexcept
    { 
        try 
        {
            descriptor << data_packet;
        }
        catch (...)
        {
            return false;
        }
        return true;
    }


};


