#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

// https://wiki.qt.io/Doxygen_Plugin_for_QtCreator

struct sSListNode
{
    struct sSListNode *pNext;
    int         value;
};

typedef struct
{
    struct sSListNode *pHead;
    unsigned           size;
}sSList;

typedef int(*slt_pfsort)(int, int);

/*
void   slt_init(sSList *);
void   slt_free(sSList *);
int    slt_is_empty(sSList *);

struct sSListNode *slt_append(sSList *, int);
struct sSListNode *slt_insert_at_begin(sSList *, int);
struct sSListNode *slt_insert_by_index(sSList *, unsigned, int);
struct sSListNode *slt_insert_by_pointer(sSList *, struct sSListNode *, int);
struct sSListNode *slt_remove_first(sSList *);
struct sSListNode *slt_remove_last(sSList *);
struct sSListNode *slt_remove_by_index(sSList *, unsigned);
struct sSListNode *slt_remove_by_pointer(sSList *, struct sSListNode *);
struct sSListNode *slt_find(sSList *, int);
struct sSListNode *slt_first(sSList *);
struct sSListNode *slt_last(sSList *);
struct sSListNode *slt_next(struct sSListNode *);

void   slt_print(sSList *);
*/


/*
+---------+
|  pHead  | = NULL
+---------+
|  pList  | = NULL
+---------+
|  size   | = 0
+---------+
*/
void slt_init(sSList *);

/*
while !NULL
    next = current->next
    free(current)
    next = current
*/
void slt_free(sSList *);

int slt_is_empty(sSList *);

/*
                              +---------+
                              |  value  |
                              +---------+
                              |         |
                              +---------+
+---------+    +---------+
|  value  |    |  value  |
+---------+ .->+---------+
|  pNext  |-.  |   NULL  |
+---------+    +---------+

after append
                               +---------+
                               |  value  |
                            .->+---------+
                            |  |   NULL  |
                            |  +---------+
+---------+    +---------+  |
|  value  |    |  value  |  |
+---------+ .->+---------+  |
|  pNext  |-.  |   pNext |--.
+---------+    +---------+
*/
struct sSListNode * slt_append(sSList *, int);

/*
                 +---------+
                 |  value  |
                 +---------+
                 |         |
                 +---------+

+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+

after insert (insert after index or pointer)
                 +---------+
                 |  value  |
            .--->+---------+
            |    |  pNext  |--.
            |    +---------+  |
            |                 |
            |  .--------------.
+---------+ |  |  +---------+      +---------+
|  value  | |  |  |  value  |      |  value  |
+---------+ |  .->+---------+  .-->+---------+
|  pNext  |-.     |  pNext  |--.   |   NULL  |
+---------+       +---------+      +---------+
*/
struct sSListNode * slt_insert_at_begin(sSList *, int);
struct sSListNode * slt_insert_by_index(sSList *, unsigned, int);
struct sSListNode * slt_insert_by_pointer(sSList *, struct sSListNode *, int);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+

after remove
free(first)

pHead = -----.
             |
+---------+  |   +---------+      +---------+
| REMOVED |  |   |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
| REMOVED |      |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+
*/
struct sSListNode * slt_remove_first(sSList *);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+

after remove
free(last)

+---------+     +---------+    +---------+
|  value  |     |  value  |    | REMOVED |
+---------+  .->+---------+    +---------+
|  pNext  |--.  |   NULL  |    | REMOVED |
+---------+     +---------+    +---------+
*/
struct sSListNode * slt_remove_last(sSList *);

/*
+---------+      +---------+      +---------+
|  value  |      |  value  |      |  value  |
+---------+  .-->+---------+  .-->+---------+
|  pNext  |--.   |  pNext  |--.   |   NULL  |
+---------+      +---------+      +---------+

after remove (remove by index or pointer)

             .---------------.
+---------+  |  +---------+  |  +---------+
|  value  |  |  | REMOVED |  |  |  value  |
+---------+  |  +---------+  .->+---------+
|  pNext  |--.  | REMOVED |     |   NULL  |
+---------+     +---------+     +---------+
*/
struct sSListNode * slt_remove_by_index(sSList *, unsigned);
struct sSListNode * slt_remove_by_pointer(sSList *, struct sSListNode *);

struct sSListNode * slt_find(sSList *, int);

struct sSListNode *slt_first(sSList *);
struct sSListNode *slt_last(sSList *);
struct sSListNode *slt_next(struct sSListNode *);

void slt_sort(sSList *);
void slt_sort_custom(sSList *, slt_pfsort);

void slt_print(sSList *);

#endif // SINGLE_LIST_H



























