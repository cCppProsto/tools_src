#ifndef INPUT_TOOLS_H
#define INPUT_TOOLS_H

// https://wiki.qt.io/Doxygen_Plugin_for_QtCreator

typedef enum
{
    KEY_UNKNOWN = 0
   ,KEY_ENTER
   ,KEY_SPACE
   ,KEY_ESC
   ,KEY_UP
   ,KEY_RIGTH
   ,KEY_DOWN
   ,KEY_LEFT
}eKeyKode;

eKeyKode it_get_key();

#endif // INPUT_TOOLS_H
