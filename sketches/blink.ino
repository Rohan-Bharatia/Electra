// This is a recreation of the Arduino Example 'blink.ino' sketch

#define __ARDUINO_UNO__
#include "electra.h"

int main()
{
    set(LED_BUILTIN, OUTPUT);

    while(true)
    {
        digital::write(LED_BUILTIN, HIGH);

        wait(200);

        digital::write(LED_BUILTIN, LOW);

        wait(200);
    }
    return 0;
}