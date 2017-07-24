#include "input_tools.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void it_init()
{
#ifdef _WIN32
#elif defined __unix__
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  cbreak();
  timeout(-1);
  curs_set(0);
#endif
}

#ifdef _WIN32
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
#elif defined __unix__
#include <ncurses.h>

eKeyKode it_get_key()
{
  int key = getch();
  refresh();

  switch(key)
  {
    case KEY_UP:
      return IT_KEY_UP;
    case KEY_RIGHT:
      return IT_KEY_RIGTH;
    case KEY_DOWN:
      return IT_KEY_DOWN;
    case KEY_LEFT:
      return IT_KEY_LEFT;
    case KEY_ENTER:
    case 10:
      return IT_KEY_ENTER;
    case 32:
      return IT_KEY_SPACE;
    case 27:
      return IT_KEY_ESC;
  }
  return IT_KEY_UNKNOWN;
}
#endif

void it_new_line()
{
#ifdef _WIN32
  printf("\n");
#elif defined __unix__
  printw("\n");
#endif
}

void it_clrscr()
{
#ifdef _WIN32
  system("cls");
#elif defined __unix__
  system("clear");
  clear();
#endif
}

