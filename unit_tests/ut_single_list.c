#include <stdlib.h>
#include <stdio.h>

#include "ut_single_list.h"
#include "../single_list.h"

void _print_test_result(unsigned aIsPrint, int aResult, const char *apStr, unsigned aNumber)
{
    if(aIsPrint)
        printf("%s : Test %.2i - %s\n", apStr, aNumber, aResult ? "Passed": "Fail");
}

//------------------------------------------------------------------------------
void ut_single_list_init(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;

    slt_init(&list);

    _print_test_result(aIsPrint, slt_is_empty(&list) == 1,  __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead == NULL,        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 0,            __FUNCTION__, test_number++);
    if(aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_append(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);
    
    tmp = slt_append(&list, 1); //            -  1
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_append(&list, 2); // 1          -  1, 2
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_append(&list, 3); // 1, 2       -  1, 2, 3
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_append(&list, 4); // 1, 2, 3    -  1, 2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    _print_test_result(aIsPrint, list.pHead != NULL,                            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,                                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 1,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 2,                 __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 3,          __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->pNext->value == 4,   __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_insert_at_begin(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    tmp = slt_insert_at_begin(&list, 1); //           - 1
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_insert_at_begin(&list, 2); // 1         - 2, 1
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_insert_at_begin(&list, 3); // 2, 1      - 3, 2, 1
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_insert_at_begin(&list, 4); // 3, 2, 1   - 4, 3, 2, 1
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    _print_test_result(aIsPrint, list.pHead != NULL,                            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,                                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 4,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 3,                 __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 2,          __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->pNext->value == 1,   __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_insert_by_index(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);
    tmp = slt_insert_at_begin(&list, 1);      //              - 1
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_insert_by_index(&list, 0, 2);   // 1            - 1, 2
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);
    
    tmp = slt_insert_by_index(&list, 1, 3);   // 1, 2         - 1, 2, 3
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_insert_by_index(&list, 1, 4);   // 1, 2, 3      - 1, 2, 4, 3
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    tmp = slt_insert_by_index(&list, 3, 5);   // 1, 2, 4, 3   - 1, 2, 4, 3, 5
    _print_test_result(aIsPrint, tmp->value == 5, __FUNCTION__, test_number++);

    _print_test_result(aIsPrint, list.pHead != NULL,                                    __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 5,                                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 1,                                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 2,                         __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 4,                  __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->pNext->value == 3,           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->pNext->pNext->value == 5,    __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_insert_by_pointer(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);
    tmp = slt_insert_at_begin(&list, 1);                              //              - 1
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_insert_by_pointer(&list, list.pHead, 2);                // 1            - 1, 2
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_insert_by_pointer(&list, list.pHead, 3);                // 1, 2         - 1, 3, 2
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_insert_by_pointer(&list, list.pHead->pNext->pNext, 4);  // 1, 3, 2      - 1, 3, 2, 4
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    _print_test_result(aIsPrint, list.pHead != NULL,                            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,                                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 1,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 3,                 __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 2,          __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->pNext->value == 4,   __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_remove_first(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 3);
    slt_append(&list, 4);   // 1, 2, 3, 4

    _print_test_result(aIsPrint, list.pHead != NULL,        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,            __FUNCTION__, test_number++);

    tmp = slt_remove_first(&list); // 1, 2, 3, 4      -   2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 2,           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 3,            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 2,    __FUNCTION__, test_number++);

    tmp = slt_remove_first(&list); // 2, 3, 4      -   3, 4
    _print_test_result(aIsPrint, tmp->value == 3,           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 2,            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 3,    __FUNCTION__, test_number++);

    tmp = slt_remove_first(&list); // 3, 4      -   4
    _print_test_result(aIsPrint, tmp->value == 4,           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 1,            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 4,    __FUNCTION__, test_number++);

    tmp = slt_remove_first(&list); // 4      -   
    _print_test_result(aIsPrint, tmp       == NULL,         __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 0,            __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead == NULL,        __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_remove_last(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 3);
    slt_append(&list, 4);   // 1, 2, 3, 4

    _print_test_result(aIsPrint, list.pHead != NULL,    __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,        __FUNCTION__, test_number++);

    tmp = slt_remove_last(&list); // 1, 2, 3, 4       - 1, 2, 3
    _print_test_result(aIsPrint, tmp       == NULL,                      __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 3,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 3,  __FUNCTION__, test_number++);

    tmp = slt_remove_last(&list); // 1, 2, 3          -  1, 2 
    _print_test_result(aIsPrint, tmp == NULL,                           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 2,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 2,         __FUNCTION__, test_number++);

    tmp = slt_remove_last(&list); // 1, 2             - 1
    _print_test_result(aIsPrint, tmp == NULL,                           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 1,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 1,                __FUNCTION__, test_number++);

    tmp = slt_remove_last(&list); // 4                - 
    _print_test_result(aIsPrint, tmp == NULL,                           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 0,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead == NULL,                    __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_remove_by_index(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 5);
    slt_append(&list, 3);
    slt_append(&list, 4);   // 1, 2, 5, 3, 4

    tmp = slt_remove_by_index(&list, 2);  // 1, 2, 5, 3, 4       - 1, 2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 3,                       __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 3,  __FUNCTION__, test_number++);

    tmp = slt_remove_by_index(&list, 0);  // 1, 2, 3, 4       - 2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 2,               __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 3,                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 2,        __FUNCTION__, test_number++);

    tmp = slt_remove_by_index(&list, 0);  // 2, 3, 4          - 3, 4
    _print_test_result(aIsPrint, tmp->value == 3,               __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 2,                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 3,        __FUNCTION__, test_number++);

    tmp = slt_remove_by_index(&list, 1);  // 3, 4             - 3
    _print_test_result(aIsPrint, tmp == NULL,                   __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 1,                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 3,        __FUNCTION__, test_number++);

    tmp = slt_remove_by_index(&list, 0);  // 3                - 
    _print_test_result(aIsPrint, tmp == NULL,                   __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 0,                __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead == NULL,            __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_remove_by_pointer(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 5);
    slt_append(&list, 3);
    slt_append(&list, 4);   // 1, 2, 5, 3, 4

    tmp = slt_remove_by_pointer(&list, list.pHead->pNext->pNext);  // 1, 2, 5, 3, 4       - 1, 2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 3,                       __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 4,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->pNext->pNext->value == 3,  __FUNCTION__, test_number++);

    tmp = slt_remove_by_pointer(&list, list.pHead);  // 1, 2, 3, 4       - 2, 3, 4
    _print_test_result(aIsPrint, tmp->value == 2,                       __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 3,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 2,                __FUNCTION__, test_number++);

    tmp = slt_remove_by_pointer(&list, list.pHead);  // 2, 3, 4          - 3, 4
    _print_test_result(aIsPrint, tmp->value == 3,                       __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 2,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 3,                __FUNCTION__, test_number++);

    tmp = slt_remove_by_pointer(&list, list.pHead->pNext);  // 3, 4             - 3
    _print_test_result(aIsPrint, tmp == NULL,                           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 1,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead->value == 3,                __FUNCTION__, test_number++);

    tmp = slt_remove_by_pointer(&list, list.pHead);  // 3                - 
    _print_test_result(aIsPrint, tmp == NULL,                           __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.size == 0,                        __FUNCTION__, test_number++);
    _print_test_result(aIsPrint, list.pHead == NULL,                    __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_find(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 3);
    slt_append(&list, 4);
    slt_append(&list, 5); // 1, 2, 3, 4, 5

    unsigned index = 0;
    tmp = slt_find(&list, 1);
    _print_test_result(aIsPrint, tmp->value == 1,   __FUNCTION__, test_number++);

    tmp = slt_find(&list, 5);
    _print_test_result(aIsPrint, tmp->value == 5,   __FUNCTION__, test_number++);

    tmp = slt_find(&list, 3);
    _print_test_result(aIsPrint, tmp->value == 3,   __FUNCTION__, test_number++);

    tmp = slt_find(&list, 10);
    _print_test_result(aIsPrint, tmp == NULL,       __FUNCTION__, test_number++);

    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_first_last_next(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;

    slt_init(&list);

    slt_append(&list, 1);
    slt_append(&list, 2);
    slt_append(&list, 3);
    slt_append(&list, 4);
    slt_append(&list, 5); // 1, 2, 3, 4, 5

    struct sSListNode *tmp;
    tmp = slt_first(&list);
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 5, __FUNCTION__, test_number++);

    tmp = slt_last(&list);
    _print_test_result(aIsPrint, tmp->value == 5, __FUNCTION__, test_number++);

    slt_remove_by_pointer(&list, tmp);
    tmp = slt_last(&list);
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    tmp = slt_first(&list);
    slt_insert_by_pointer(&list, tmp, 100);
    _print_test_result(aIsPrint, list.pHead->pNext->value == 100, __FUNCTION__, test_number++);

    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_sort(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 5);
    slt_append(&list, 4);
    slt_append(&list, 3);
    slt_append(&list, 2);
    slt_append(&list, 1); 
    slt_append(&list, 3);
    slt_append(&list, 3);
    slt_append(&list, 2); 
    slt_append(&list, 100); // 5, 4, 3, 2, 1, 3, 3, 2, 100

    slt_sort(&list);

    tmp = slt_first(&list);
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 5, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 100, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp == NULL,       __FUNCTION__, test_number++);
    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}

int ascending(int a, int b)  // >
{
    return a <= b;
}
int descending(int a, int b) // <
{
    return a >= b;
}
//------------------------------------------------------------------------------
void ut_single_list_sort_custom_ascending(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 5);
    slt_append(&list, 4);
    slt_append(&list, 3);
    slt_append(&list, 2);
    slt_append(&list, 1);
    slt_append(&list, 3);
    slt_append(&list, 3);
    slt_append(&list, 2);
    slt_append(&list, 100); // 5, 4, 3, 2, 1, 3, 3, 2, 100

    slt_sort_custom(&list, ascending);

    tmp = slt_first(&list);
    _print_test_result(aIsPrint, tmp->value == 1, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 4, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 5, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 100, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp == NULL, __FUNCTION__, test_number++);

    if (aIsPrint)
        printf("\n");

    slt_free(&list);
}
//------------------------------------------------------------------------------
void ut_single_list_sort_custom_descending(unsigned aIsPrint)
{
    int test_number = 1;
    sSList list;
    struct sSListNode *tmp;

    slt_init(&list);

    slt_append(&list, 5);
    slt_append(&list, 4);
    slt_append(&list, 3);
    slt_append(&list, 2);
    slt_append(&list, 1);
    slt_append(&list, 3);
    slt_append(&list, 3);
    slt_append(&list, 2);
    slt_append(&list, 100); // 5, 4, 3, 2, 1, 3, 3, 2, 100

    slt_sort_custom(&list, ascending);
    slt_sort_custom(&list, descending);

    tmp = slt_first(&list);
    _print_test_result(aIsPrint, tmp->value == 100, __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 5,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 4,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 3,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 2,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp->value == 1,   __FUNCTION__, test_number++);

    tmp = slt_next(tmp);
    _print_test_result(aIsPrint, tmp == NULL,       __FUNCTION__, test_number++);
}
//------------------------------------------------------------------------------
void ut_single_list_common()
{
    ut_single_list_init(1);
    ut_single_list_append(1);
    ut_single_list_insert_at_begin(1);
    ut_single_list_insert_by_index(1);
    ut_single_list_insert_by_pointer(1);
    ut_single_list_remove_first(1);
    ut_single_list_remove_last(1);
    ut_single_list_remove_by_index(1);
    ut_single_list_remove_by_pointer(1);
    ut_single_list_find(1);
    ut_single_list_first_last_next(1);
    
    ut_single_list_sort(1);
    ut_single_list_sort_custom_ascending(1);
    ut_single_list_sort_custom_descending(1);

    ut_single_list_surface_memory_leaks();
}
//------------------------------------------------------------------------------
void ut_single_list_surface_memory_leaks()
{
    while (1)
    {
        ut_single_list_init(0);
        ut_single_list_append(0);
        ut_single_list_insert_at_begin(0);
        ut_single_list_insert_by_index(0);
        ut_single_list_insert_by_pointer(0);
        ut_single_list_remove_first(0);
        ut_single_list_remove_last(0);
        ut_single_list_remove_by_index(0);
        ut_single_list_remove_by_pointer(0);
        ut_single_list_first_last_next(0);
        ut_single_list_find(0);
    }
}
