#ifndef INPUT_TOOLS_H
#define INPUT_TOOLS_H

#ifdef _WIN32
#include <conio.h>
#elif defined __unix__
#include <ncurses.h>
#endif

#ifdef _WIN32
  #define IT_PRINTF(f_, ...) printf((f_), __VA_ARGS__)
#elif defined __unix__
  #define IT_PRINTF( f_ , ...) \
  printw( ( f_ ), __VA_ARGS__ ); \
  refresh();
#endif

typedef enum
{
    IT_KEY_UNKNOWN = 0
   ,IT_KEY_ENTER
   ,IT_KEY_SPACE
   ,IT_KEY_ESC
   ,IT_KEY_UP
   ,IT_KEY_RIGTH
   ,IT_KEY_DOWN
   ,IT_KEY_LEFT
}eKeyKode;

void it_init();
void it_clrscr();
int it_printf (__const char *, ...);

eKeyKode it_get_key();

#endif // INPUT_TOOLS_H
