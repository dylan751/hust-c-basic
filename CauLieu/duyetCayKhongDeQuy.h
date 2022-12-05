#include <stdio.h>
#include <stdlib.h>
#define FALSE -1

typedef int elementtype;

typedef struct node
{
  elementtype data;
  struct node *left, *right;
} node;

typedef node* tree;

void Initialize(tree* t)
{
  *t = NULL;
  return;
}

int IsEmpty(tree t)
{
  return t == NULL;
}

node* CreateNode(elementtype data)
{
  node* n = (node*)malloc(sizeof(node));
  if (n != NULL)
    {
      n->data = data;
      n->left = NULL;
      n->right = NULL;
    }
  return n;
}

int IsLeaf(tree t)
{
  if (t != NULL)
    return t->left == NULL && t->right == NULL;
  return FALSE;
}

typedef node* elementtype_stack;
struct node_stack
{
  elementtype_stack data;
  struct node_stack* next;
};
typedef struct node_stack node_stack;
typedef node_stack* stack;

void Initialize_stack(stack* top){
  *top = NULL;
  return;
}

int IsEmpty_stack(stack top){
  return (top == NULL);
}

void Push(elementtype_stack data, stack* top){
  node_stack* new;
  new = (node_stack*) malloc (sizeof(node_stack));
  new->data = data;
  new->next = *top;
  *top = new;
  return;
}

elementtype_stack Pop(stack* top){
  if (IsEmpty_stack(*top)){
      printf("Stack_stack underflow Pop\n");
      return FALSE;
  }
  elementtype_stack result = (*top)->data;
  node_stack* del = *top;
  *top = (*top)->next;
  free(del);
  return result;
}

elementtype_stack Peek(stack top){
  if (IsEmpty_stack(top)){
    printf("Stack underflow Peek\n");
    return FALSE;
  }
  return top->data;
}
void DisplayNode(tree t){
  printf("%d\t", t->data);
}

void InOrderPrint(tree t){
  if (t != NULL){
    InOrderPrint(t->left);
    DisplayNode(t);
    InOrderPrint(t->right);
  }
  return;
}

void Insert(tree* t, elementtype data){
  if (*t == NULL)
    *t = CreateNode(data);
  else if (data > (*t)->data)
    Insert( &(*t)->right, data);
  else
    Insert( &(*t)->left, data);
}

void PostOrderPrint(tree t){
  if (t != NULL){
    PostOrderPrint(t->left);
    PostOrderPrint(t->right);
    DisplayNode(t);
  }
}
