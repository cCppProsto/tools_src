#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binary_tree.h"

static sBinTreeNode *pi_insert(sBinTreeNode *, sLeaf *);
static sLeaf        *pi_search(sBinTreeNode *, int *);
static void          pi_destroy(sBinTreeNode *);

static sBinTreeNode* pi_ll_rotation(sBinTreeNode *);
static sBinTreeNode* pi_rr_rotation(sBinTreeNode *);
static sBinTreeNode* pi_lr_rotation(sBinTreeNode *);
static sBinTreeNode* pi_rl_rotation(sBinTreeNode *);
static sBinTreeNode* pi_balance(sBinTreeNode *);

static void pi_print_in_order(sBinTreeNode *);
static void pi_print_pre_order(sBinTreeNode *);
static void pi_print_post_order(sBinTreeNode *);

static char pi_height(sBinTreeNode *);
static char pi_diff(sBinTreeNode *);

//------------------------------------------------------------------------------
void bt_init(sBinTree *apTree)
{
  apTree->pRoot = NULL;
  apTree->l_depth = 0;
  apTree->r_depth = 0;
}
//------------------------------------------------------------------------------
void bt_destroy(sBinTree *apTree)
{
  pi_destroy(apTree->pRoot);
}
//------------------------------------------------------------------------------
void bt_insert(sBinTree *apTree, sLeaf *apLeaf)
{
  apTree->pRoot = pi_insert(apTree->pRoot, apLeaf);
}
//------------------------------------------------------------------------------
sLeaf *bt_search(sBinTree *apTree, int aKey)
{
  return pi_search(apTree->pRoot, &aKey);
}
//------------------------------------------------------------------------------
void bt_in_order_print(sBinTree *apTree)
{
  pi_print_in_order(apTree->pRoot);
  printf("\n");
}
//------------------------------------------------------------------------------
void bt_pre_order_print(sBinTree *apTree)
{
  pi_print_pre_order(apTree->pRoot);
  printf("\n");
}
//------------------------------------------------------------------------------
void bt_post_order_print(sBinTree *apTree)
{
  pi_print_post_order(apTree->pRoot);
  printf("\n");
}
//------------------------------------------------------------------------------
//------------------ PRIVATE IMPLEMENTATION ------------------------------------
//------------------------------------------------------------------------------
sBinTreeNode *pi_insert(sBinTreeNode *apNode, sLeaf *apLeaf)
{
  if(apNode == NULL)
  {
    apNode = (sBinTreeNode *)malloc(sizeof(sBinTreeNode));
    apNode->pLeft   = NULL;
    apNode->pRight  = NULL;

    apNode->data.key   = apLeaf->key;
    apNode->data.value = apLeaf->value;
  }
  else
  {
    if(apLeaf->key < apNode->data.key)
    {
      sBinTreeNode *added = NULL;
      added = pi_insert(apNode->pLeft, apLeaf);
      apNode->pLeft = added;
      apNode = pi_balance(apNode);
    }

    if(apLeaf->key > apNode->data.key)
    {
      sBinTreeNode *added = NULL;
      added = pi_insert(apNode->pRight, apLeaf);
      apNode->pRight = added;
      apNode = pi_balance(apNode);
    }
  }
  return apNode;
}
//------------------------------------------------------------------------------
sBinTreeNode* pi_balance(sBinTreeNode *temp)
{
  int bal_factor = pi_diff(temp);
  if (bal_factor > 1)
  {
    if (pi_diff(temp->pLeft) > 0)
      temp = pi_ll_rotation(temp);
    else
      temp = pi_lr_rotation(temp);
  }
  else if (bal_factor < -1)
  {
    if (pi_diff(temp->pRight) > 0)
      temp = pi_rl_rotation(temp);
    else
      temp = pi_rr_rotation(temp);
  }
  return temp;
}
//------------------------------------------------------------------------------
sLeaf *pi_search(sBinTreeNode *apNode, int *apKey)
{
  if( apNode != NULL )
  {
    if(*apKey == apNode->data.key)
      return &(apNode->data);

    if(*apKey < apNode->data.key)
      return pi_search(apNode->pLeft, apKey);

    if(*apKey > apNode->data.key)
      return pi_search(apNode->pRight, apKey);
  }
  return NULL;
}
//------------------------------------------------------------------------------
void pi_destroy(sBinTreeNode *apNode)
{
  if( apNode != NULL )
  {
      pi_destroy(apNode->pLeft);
      pi_destroy(apNode->pRight);
      free( apNode );
  }
}
//------------------------------------------------------------------------------
char pi_height(sBinTreeNode *apNode)
{
  int h = 0;

  if (apNode != NULL)
  {
      int l_height = pi_height(apNode->pLeft);
      int r_height = pi_height(apNode->pRight);
      int max_height = l_height > r_height ? l_height : r_height;
      h = max_height + 1;
  }
  return h;
}
//------------------------------------------------------------------------------
char pi_diff(sBinTreeNode *apNode)
{
  int l_height = pi_height(apNode->pLeft);
  int r_height = pi_height(apNode->pRight);
  int b_factor = l_height - r_height;
  return b_factor;
}
//------------------------------------------------------------------------------
sBinTreeNode* pi_ll_rotation(sBinTreeNode *apNode)
{
  sBinTreeNode *temp;
  temp = apNode->pLeft;
  apNode->pLeft = temp->pRight;
  temp->pRight = apNode;
  return temp;
}
//------------------------------------------------------------------------------
sBinTreeNode* pi_rr_rotation(sBinTreeNode *apNode)
{
  sBinTreeNode *temp;
  temp = apNode->pRight;
  apNode->pRight = temp->pLeft;
  temp->pLeft = apNode;
  return temp;
}
//------------------------------------------------------------------------------
sBinTreeNode* pi_lr_rotation(sBinTreeNode *apNode)
{
  sBinTreeNode *temp;
  temp = apNode->pLeft;
  apNode->pLeft = pi_rr_rotation(temp);
  return pi_ll_rotation(apNode);
}
//------------------------------------------------------------------------------
sBinTreeNode* pi_rl_rotation(sBinTreeNode *apNode)
{
  sBinTreeNode *temp;
  temp = apNode->pRight;
  apNode->pRight = pi_ll_rotation(temp);
  return pi_rr_rotation(apNode);
}
//------------------------------------------------------------------------------
void pi_print_in_order(sBinTreeNode *apNode)
{
  if(apNode != NULL)
  {
    pi_print_in_order(apNode->pLeft);
    //printf("%d, ", apNode->data.value.data);
    printf("%d, ", apNode->data.key);
    pi_print_in_order(apNode->pRight);
  }
}
//------------------------------------------------------------------------------
void pi_print_pre_order(sBinTreeNode *apNode)
{
  if(apNode != NULL)
  {
    //printf("%d, ", apNode->data.value.data);
    printf("%d, ", apNode->data.key);
    pi_print_pre_order(apNode->pLeft);
    pi_print_pre_order(apNode->pRight);
  }
}
//------------------------------------------------------------------------------
void pi_print_post_order(sBinTreeNode *apNode)
{
  if(apNode != NULL)
  {
    pi_print_pre_order(apNode->pLeft);
    pi_print_pre_order(apNode->pRight);
    //printf("%d, ", apNode->data.value.data);
    printf("%d, ", apNode->data.key);
  }
}






