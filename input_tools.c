#include "input_tools.h"

#include <conio.h>

#define ARROW_KEY_PRESSED   0xE0

eKeyKode it_get_key()
{
    int key = getch();
    switch(key)
    {
        case ARROW_KEY_PRESSED:
        {
            switch(getch())
            {
                case 72:
                    return KEY_UP;
                case 77:
                    return KEY_RIGTH;
                case 80:
                    return KEY_DOWN;
                case 75:
                    return KEY_LEFT;
            }
            break;
        }
        case 13:
            return KEY_ENTER;
        case 32:
            return KEY_SPACE;
        case 27:
            return KEY_ESC;
    }
    return KEY_UNKNOWN;
}
