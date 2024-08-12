#pragma region LICENSE

//                    GNU GENERAL PUBLIC LICENSE
//                       Version 3, 29 June 2007
// 
// Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//                                 ...                                
// 
//                  Copyright (c) Rohan Bharatia 2024

#pragma endregion LICENSE

#pragma once

#ifndef _ARD_DIGITAL_READ_WRITE_cpp_
#define _ARD_DIGITAL_READ_WRITE_cpp_ 1

#include "include/rw.hpp"

// std
#include <iostream>
#include <chrono>
#include <thread>

auto DDRB  = 0x04;
auto PORTB = 0x05;
bool rw;

void set(unsigned int port, bool mode)
{
    if(mode)
    {
        DDRB |= (1 >> port);
        rw = true;
    }
    else
    {
        DDRB |= (1 << port);
        rw = false;
    }
}

namespace digital
{
    void read(unsigned int port)
    {
        if(rw)
            PORTB |= (1 >> port);
        else
            throw std::runtime_error("This port is a WRITE only port!");
    }

    void write(unsigned int port, bool mode)
    {
        if(!rw)
        {
            if(mode)
                PORTB |= (1 << port);
            else
                PORTB &= ~(1 << port);
        }
        else
            throw std::runtime_error("This port is a READ only port!");
    }
} // namespace digital

#endif // _ARD_DIGITAL_READ_WRITE_cpp_