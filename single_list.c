#include <stdlib.h>
#include <stdio.h>

#include "single_list.h"


struct sSListNode * _get_new_node(int aValue)
{
    struct sSListNode *res;
    res = (struct sSListNode*)malloc(sizeof(struct sSListNode));
    res->value = aValue;
    res->pNext = NULL;
    return res;
}

//------------------------------------------------------------------------------
void slt_init(sSList *apList)
{
    apList->pHead = NULL;
    apList->size  = 0;
}
//------------------------------------------------------------------------------
void slt_free(sSList *apList)
{
    struct sSListNode *next = apList->pHead;
    struct sSListNode *tmp;
    while(next)
    {
        tmp = next->pNext;
        free(next);
        next = tmp;
    }
    apList->pHead = NULL;
    apList->size  = 0;
}
//------------------------------------------------------------------------------
int slt_is_empty(sSList *apList)
{
    return (apList->pHead == NULL);
}
//------------------------------------------------------------------------------
struct sSListNode * slt_append(sSList *apList, int aValue)
{
    struct sSListNode *next = apList->pHead;
    if (next == NULL)
    {
        apList->pHead = _get_new_node(aValue);
        apList->size++;
        return apList->pHead;
    }

    while(next->pNext)
        next = next->pNext;

    next->pNext = _get_new_node(aValue);
    apList->size++;
    return next->pNext;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_insert_at_begin(sSList *apList, int aValue)
{
    if (apList->pHead == NULL)
        return slt_append(apList, aValue);

    struct sSListNode *tmp;
    struct sSListNode *new_element;

    tmp = apList->pHead;

    new_element          = _get_new_node(aValue);
    apList->pHead        = new_element;
    apList->pHead->pNext = tmp;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_insert_by_index(sSList *apList, unsigned aIndex, int aValue)
{
    if (aIndex >= apList->size)
        return NULL;

    unsigned i = 0;
    struct sSListNode *next = apList->pHead;
    struct sSListNode *tmp;
    struct sSListNode *new_element;

    while(i++ < aIndex)
        next = next->pNext;

    new_element        = _get_new_node(aValue);
    tmp                = next->pNext;
    next->pNext        = new_element;
    new_element->pNext = tmp;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_insert_by_pointer(sSList *apList, struct sSListNode *apNode, int aValue)
{
    unsigned i = 0;
    struct sSListNode *next = apList->pHead;
    struct sSListNode *tmp;
    struct sSListNode *new_element;

    // TODO !!!!!!!!!!!!!
    while (next != apNode)
        next = next->pNext;
    // !!!!!!!!!!!!!!!!!!!!

    new_element        = _get_new_node(aValue);
    tmp                = next->pNext;
    next->pNext        = new_element;
    new_element->pNext = tmp;
    apList->size++;
    return new_element;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_remove_first(sSList *apList)
{
    if (apList->pHead == NULL)
        return NULL;

    struct sSListNode *tmp;
    tmp = apList->pHead->pNext;
    free(apList->pHead);
    apList->pHead = tmp;
    apList->size--;
    return apList->pHead;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_remove_last(sSList *apList)
{
    if (apList->pHead == NULL)
        return NULL;

    struct sSListNode *last;
    struct sSListNode *prev;

    last = apList->pHead;
    prev = last;
    while (last->pNext)
    {
        prev = last;
        last = last->pNext;
    }

    free(last);
    prev->pNext = NULL;
    apList->size--;

    if (apList->size == 0)
        apList->pHead = NULL;

    return NULL;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_remove_by_index(sSList *apList, unsigned aIndex)
{
    if (aIndex >= apList->size)
        return NULL;

    if (aIndex == 0)
        return slt_remove_first(apList);

    if (aIndex == (apList->size - 1))
        return slt_remove_last(apList);

    unsigned i = 0;
    struct sSListNode *current;
    struct sSListNode *prev;

    current = apList->pHead;
    prev    = current;
    while (i++ < aIndex)
    {
        prev    = current;
        current = current->pNext;
    }

    prev->pNext = current->pNext;
    free(current);
    apList->size--;
    return prev->pNext;
}
//------------------------------------------------------------------------------
struct sSListNode * slt_remove_by_pointer(sSList *apList, struct sSListNode *apNode)
{
    if (apNode == NULL || apList->size == 0)
        return NULL;

    unsigned i = 0;
    struct sSListNode *next = apList->pHead;

    while (next != apNode)
    {
        next = next->pNext;
        ++i;
    }

    return slt_remove_by_index(apList, i);
}
//------------------------------------------------------------------------------
struct sSListNode * slt_find(sSList *apList, int aValue)
{
    struct sSListNode *cur = apList->pHead;

    unsigned i = 0;
    while (cur)
    {
        if (cur->value == aValue)
            return cur;
        cur = cur->pNext;
        ++i;
    }
    return NULL;
}
//------------------------------------------------------------------------------
struct sSListNode *slt_first(sSList *apList)
{
    return apList->pHead;
}
//------------------------------------------------------------------------------
struct sSListNode *slt_last(sSList *apList)
{
    struct sSListNode *next = apList->pHead;
    while (next->pNext)
        next = next->pNext;
    return next;
}
//------------------------------------------------------------------------------
struct sSListNode *slt_next(struct sSListNode *apNode)
{
    if (apNode == NULL)
        return NULL;
    
    if (apNode->pNext != NULL)
        return apNode->pNext;
    return NULL;
}
//------------------------------------------------------------------------------
void slt_sort(sSList *apList)
{
    struct sSListNode *i;
    struct sSListNode *j;

    i = apList->pHead;
    while (i)
    {
        for (j = i->pNext; j && i->value <= j->value; j = j->pNext)
            ;

        if (j != NULL)
        {
            int tmp;
            tmp = j->value;
            j->value = i->value;
            i->value = tmp;
        }
        else
            i = i->pNext;
    }
}
//------------------------------------------------------------------------------
void slt_sort_custom(sSList *apList, slt_pfsort apfSort)
{
    struct sSListNode *i;
    struct sSListNode *j;

    i = apList->pHead;
    while (i)
    {
        for (j = i->pNext; j && apfSort(i->value, j->value); j = j->pNext)
            ;

        if (j != NULL)
        {
            int tmp;
            tmp = j->value;
            j->value = i->value;
            i->value = tmp;
        }
        else
            i = i->pNext;
    }
}
//------------------------------------------------------------------------------
void slt_print(sSList *apList)
{
    struct sSListNode *next = apList->pHead;
    while(next)
    {
        printf("%i ", next->value);
        next = next->pNext;
    }
    printf("\n");
}
