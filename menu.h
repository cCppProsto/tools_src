#ifndef _MENU_H_
#define _MENU_H_

#include <stdbool.h>

typedef struct sMenu sMenu;
typedef struct sMenuItem sMenuItem;

typedef struct sMenuValue
{
    char *str;
    int  id;
}sMenuValue;

struct sMenuItem
{
    sMenuValue    value;
    sMenu        *child;
    sMenuItem    *next;
    sMenuItem    *prev;
};

struct sMenu
{
    sMenuItem *current;
    sMenuItem *first;
    sMenuItem *last;
    sMenu     *parent;
    unsigned   count;
};

sMenu      *menu_create();
void        menu_destroy(sMenu **);

sMenuItem *menu_add_item(sMenu *, char const *, unsigned);
sMenu     *menu_create_sub_menu(sMenu *, sMenuItem *);

sMenuItem  *menu_first_item(sMenu *);
sMenuItem  *menu_last_item(sMenu *);
sMenuItem  *menu_next_item(sMenuItem *);
sMenuItem  *menu_prev_item(sMenuItem *);

bool menu_item_is_selected(sMenu *, sMenuItem *);
bool menu_select_next(sMenu *);
bool menu_select_prev(sMenu *);
void menu_select_first(sMenu *);
void menu_select_last(sMenu *);

sMenu *menu_sub_enter(sMenu *);
sMenu *menu_sub_leave(sMenu *);

sMenuItem  *menu_current_item(sMenu const*);
sMenuValue *menu_current_value(sMenu const*);

unsigned   menu_items_count(sMenu *);




#endif /* _MENU_H_ */
