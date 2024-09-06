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

#ifndef _ARD_UNO_PORTS_h_
#define _ARD_UNO_PORTS_h_ 1

// Analog ports are for reading raw sensor data
// Analog ports
enum AnalogPort
{
    A0 = 0,
    A1 = 1,
    A2 = 2,
    A3 = 3,
    A4 = 4,
    A5 = 5
};

// Digital ports are for reading and writing analog and non-analog data
// GPIO (General-Purpose Input/Output) ports
enum GPIOPort
{
    PORT0  = 0,
    PORT1  = 1,
    PORT2  = 2,
    PORT3  = 3,
    PORT4  = 4,
    PORT5  = 5,
    PORT6  = 6,
    PORT7  = 7,
    PORT8  = 8,
    PORT9  = 9,
    PORT10 = 10,
    PORT11 = 11,
    PORT12 = 12,
    PORT13 = 13
};

// PWM compatible GPIO ports
enum PWMPort
{
    PORT3  = GPIOPort::PORT3,
    PORT5  = GPIOPort::PORT5,
    PORT6  = GPIOPort::PORT6,
    PORT9  = GPIOPort::PORT9,
    PORT10 = GPIOPort::PORT10,
    PORT11 = GPIOPort::PORT11
};

// LED port
#define LED_BUILTIN 5

#endif // _ARD_UNO_PORTS_h_