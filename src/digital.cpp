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
#include <cstdint>

#define MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
#define SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + 0x20)

auto DDRB  = SFR_IO8(0x04);
auto PORTB = SFR_IO8(0x05);
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
