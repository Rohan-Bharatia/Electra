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

#ifndef _ARD_LIBINCLUDE_h_
#define _ARD_LIBINCLUDE_h_ 1

#ifdef __ARDUINO_UNO__

#include "include/ports/uno.h"

#elif __ARDUINO_NANO__

#include "include/ports/nano.h"

#elif __ARDUINO_MICRO__

#include "include/ports/micro.h"

#endif // __ARDUINO_UNO__

#include "include/rw.hpp"

// std
#include <chrono>
#include <thread>

// wait macro
#define wait(millis) std::this_thread::sleep_for(std::chrono::milliseconds(millis));


#endif // _ARD_LIBINCLUDE_h_