#include <stdio.h>
#include <stdlib.h>
#include "duyetCayKhongDeQuy.h"

void InOrder(tree t){
  stack s;
  Initialize_stack(&s);
  node* p = t;
  while (1){
    if (p != NULL){
      Push(p, &s);
      p = p->left;
    }
    else{
      if (IsEmpty_stack(s))
	return;
      p = Pop(&s);
      DisplayNode(p);
      p = p->right;
    }
  }
}

void PostOrder(tree t){
  stack s;
  Initialize_stack(&s);
  node* p = t, *tmp;
  while (1){
    if (p != NULL){
      if (p->right != NULL)
	Push(p->right, &s);
      Push(p, &s);
      p = p->left;
    }
    else{
      if (IsEmpty_stack(s))
	return;
      p = Pop(&s);
      if (IsEmpty_stack(s)){
	DisplayNode(p);
	return;
      }
      if (p->right == Peek(s)){
	tmp = p;
	p = Pop(&s);
	Push(tmp, &s);
      }
      else{
	DisplayNode(p);
	p = NULL;
      }
    }
  }
}

void PreOrder(tree t){
  stack s;
  Initialize_stack(&s);
  node* p = t;
  while (1){
    if (p == NULL){
      if (IsEmpty_stack(s))
	return;
      p = Pop(&s);
    }
    if (p->right != NULL)
      Push(p->right, &s);
    DisplayNode(p);
    p = p->left;
  }
}

int main(){
  int i, A[] = {10, 3, 4, 120, 35, 163, 7, 57, 312, 75, 65, 77};
  tree t = (node*)malloc(sizeof(node));
  Initialize(&t);
  for (i = 0; i < 12; ++i)
    Insert(&t, A[i]);
  printf("InOrder: ");
  InOrder(t);
  printf("\nPostOrder: ");
  PostOrder(t);
  printf("\nPreOrder: ");
  PreOrder(t);
  printf("\n");
  
  return 0;
}
