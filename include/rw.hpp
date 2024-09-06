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

#ifndef _ARD_READ_WRITE_hpp_
#define _ARD_READ_WRITE_hpp_ 1

// Tell whether to set a port to input (read) or output (write)
enum PortMode
{
    INPUT  = true,
    OUTPUT = false
};

// Tell whether to set a port to high (5v) or low (0v)
enum WriteMode
{
    HIGH = true,
    LOW  = false
};

// Set a port to an I/O mode
void set(unsigned int port, bool mode);

namespace digital
{
    // Read data from a port
    void read(unsigned int port);
    // Write data to a port
    void write(unsigned int port, bool mode);
} // namespace digital

#endif // _ARD_READ_WRITE_hpp_