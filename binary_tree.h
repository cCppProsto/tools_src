#ifndef _BINARY_INT_TREE_H_
#define _BINARY_INT_TREE_H_

typedef struct
{
  int data;
}sBinTreeData;

typedef struct
{
  int key;
  sBinTreeData value;
}sLeaf;

typedef struct _sBinTreeNode
{
  struct _sBinTreeNode *pLeft;
  struct _sBinTreeNode *pRight;
  sLeaf                 data;
}sBinTreeNode;

typedef struct _sBinTree
{
  unsigned char l_depth;
  unsigned char r_depth;
  sBinTreeNode *pRoot;
}sBinTree;

void bt_init(sBinTree *);
void bt_destroy(sBinTree *);

/*
вырожденное дерево
  1
   \
    2
     \
      3
       \
        4


сбалансированное дерево
         ______8______
        /             \
     __5__            _12__
    /     \          /     \
  _3_      6_       11    __15__
 /   \       \     /     /      \
2     4       7   10    14      16


1:
    NULL

2:
     __1__
    /     \
   NL      NL

3:
     __1__
    /     \
   NL   __2__
       /     \
      NL     NL

4:
     __1__
    /     \
   NL   __2__
       /     \
      NL    __3__
           /     \
          NL     NL
*/
void  bt_insert(sBinTree *, sLeaf*);
sLeaf *bt_search(sBinTree *, int);

// left node, root node and then right node.
// обход всего дерева, порядок обхода:
//     левое поддерево,
//     вершина
//     правое поддерево
// элементы в порядке возрастания
void bt_in_order_print(sBinTree *);

// root node, left node and then right node.
// обход всего дерева, порядок обхода:
//     вершина
//     левое поддерево,
//     правое поддерево
// элементы как в дереве
void bt_pre_order_print(sBinTree *);

// left node, right node and then root node.
// обход всего дерева, порядок обхода:
//     левое поддерево,
//     правое поддерево
//     вершина
// элементы в обратном порядке как в дереве
void bt_post_order_print(sBinTree *);


#endif /*_BINARY_INT_TREE_H_*/





