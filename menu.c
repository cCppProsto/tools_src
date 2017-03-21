#include <stdlib.h>
#include <string.h>

#include "menu.h"

sMenu     *create_menu();
sMenuItem *create_menu_item(char const *, unsigned);

//------------------------------------------------------------------------------
sMenu *menu_create()
{
    return create_menu();
}
//------------------------------------------------------------------------------
void menu_destroy(sMenu **apMenu)
{
    sMenuItem *item = (*apMenu)->first;
    sMenuItem *tmp  = 0;
    while (item)
    {
        if (item->child)
        {
            menu_destroy(&item->child);
            item->child = 0;
        }
        else
        {
            tmp  = item;
            item = item->next;
            free(tmp->value.str);
            free(tmp);
            tmp = 0;
        }
    }
    free(*apMenu);
    *apMenu = 0;
}
//------------------------------------------------------------------------------
sMenuItem *menu_add_item(sMenu *appMenu, char const * apStr, unsigned aID)
{
    sMenuItem *item = create_menu_item(apStr, aID);

    if (appMenu->first == 0)
    {
        appMenu->first   = item;
        appMenu->last    = item;
        appMenu->current = item;
        ++appMenu->count;
        return item;
    }

    sMenuItem *tmp;
    tmp           = appMenu->last;
    appMenu->last = item;
    item->prev    = tmp;
    tmp->next     = item;
    ++appMenu->count;
    return item;
}
//------------------------------------------------------------------------------
sMenu  *menu_create_sub_menu(sMenu *apMenu,sMenuItem *apItem)
{
    sMenu  *tmp   = create_menu();
    apItem->child = tmp;
    tmp->parent   = apMenu;
    return tmp;
}
//------------------------------------------------------------------------------
sMenuValue *menu_current_value(sMenu const *apMenu)
{
    return &apMenu->current->value;
}
//------------------------------------------------------------------------------
unsigned menu_items_count(sMenu *apMenu)
{
    return apMenu->count;
}
//------------------------------------------------------------------------------
sMenuItem  *menu_first_item(sMenu *apMenu)
{
    return apMenu->first;
}
//------------------------------------------------------------------------------
sMenuItem  *menu_last_item(sMenu *apMenu)
{
    return apMenu->last;
}
//------------------------------------------------------------------------------
sMenuItem  *menu_next_item(sMenuItem *apItem)
{
    return apItem->next;
}
//------------------------------------------------------------------------------
sMenuItem  *menu_prev_item(sMenuItem *apItem)
{
    return apItem->prev;
}
//------------------------------------------------------------------------------
bool menu_item_is_selected(sMenu *apMenu, sMenuItem *apItem)
{
    return apMenu->current == apItem;
}
//------------------------------------------------------------------------------
sMenuItem  *menu_current_item(sMenu const *apMenu)
{
    return apMenu->current;
}
//------------------------------------------------------------------------------
void menu_select_first(sMenu *apMenu)
{
    apMenu->current = apMenu->first;
}
//------------------------------------------------------------------------------
void menu_select_last(sMenu *apMenu)
{
    apMenu->current = apMenu->last;
}
//------------------------------------------------------------------------------
bool menu_select_next(sMenu *apMenu)
{
    if (apMenu->current->next != 0)
    {
        apMenu->current = apMenu->current->next;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
bool menu_select_prev(sMenu *apMenu)
{
    if (apMenu->current->prev != 0)
    {
        apMenu->current = apMenu->current->prev;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
sMenu *menu_sub_enter(sMenu *apMenu)
{
    if (apMenu->current->child != 0)
        return apMenu->current->child;
    return apMenu;
}
//------------------------------------------------------------------------------
sMenu *menu_sub_leave(sMenu *apMenu)
{
    if (apMenu->parent != 0)
        return apMenu->parent;
    return apMenu;
}
//------------------------------------------------------------------------------
sMenu *create_menu()
{
    sMenu *tmp = 0;
    tmp = (sMenu *)malloc(sizeof(sMenu));

    tmp->count = 0;
    tmp->current = 0;
    tmp->first = 0;
    tmp->last = 0;
    tmp->parent = 0;
    return tmp;
}
//------------------------------------------------------------------------------
sMenuItem *create_menu_item(char const * apStr, unsigned aID)
{
    sMenuItem *tmp = 0;

    tmp = (sMenuItem*)malloc(sizeof(sMenuItem));

    tmp->value.str = (char*)calloc(strlen(apStr) + 1, sizeof(char));
    strcpy(tmp->value.str, apStr);
    tmp->value.id = aID;

    tmp->child = 0;
    tmp->next  = 0;
    tmp->prev  = 0;

    return tmp;
}
