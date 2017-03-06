#ifndef UT_SINGLE_LIST_H
#define UT_SINGLE_LIST_H

void ut_single_list_init(unsigned);
void ut_single_list_append(unsigned);
void ut_single_list_insert_at_begin(unsigned);
void ut_single_list_insert_by_index(unsigned);
void ut_single_list_insert_by_pointer(unsigned);
void ut_single_list_remove_first(unsigned);
void ut_single_list_remove_last(unsigned);
void ut_single_list_remove_by_index(unsigned);
void ut_single_list_remove_by_pointer(unsigned);
void ut_single_list_find(unsigned);
void ut_single_list_first_last_next(unsigned);


void ut_single_list_sort(unsigned);
void ut_single_list_sort_custom_ascending(unsigned);
void ut_single_list_sort_custom_descending(unsigned);

void ut_single_list_common();
void ut_single_list_surface_memory_leaks();

#endif // UT_SINGLE_LIST_H
