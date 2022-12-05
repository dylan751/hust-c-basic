#include<stdio.h>
#include<stdlib.h>

//typedef ... elementtype;
typedef int elementtype;

typedef struct StackType_t{
  elementtype element;
  struct StackType_t *next;
}StackType;

int isEmpty(StackType *top){
  return (top == NULL);
}

void initilize(StackType **top){
  **top = NULL;
}

void push(elementtype element, StackType **top){
  StackType *p;
  p = (StackType*)malloc(sizeof(StackType));
  if(p == NULL){
    printf("Malloc Error!\n");
  }
  else{
    p->element = element;
    p->next = *top;
    *top = p;
  }
}

elementtype pop(StackType **top){
  StackType *p;
  if(!isEmpty(*top)){
    elementtype temp;
    temp = (*top)->element;
    p = *top;
    *top = (*top)->next;
    free(p);
    return temp;
  }
  else printf("Can not pop from empty stack!\n");
}

elementtype top(StackType **top){
  if(!isEmpty(*top)) return (*top)->element;
  else printf("Empty stack!\n");
}

void freeStack(StackType **top){
  StackType * to_free;
  if(isEmpty(*top)) return;
  to_free = *top;
  while(to_free != NULL){
    *top = (*top)->next;
    free(to_free);
    to_free = *top;
  }
}
