/*
Thu vien: Ngan xep (stack) dung mang kieu cau truc
*/

#include<stdio.h>
#define MAX 100

/*Co the thay kieu du lieu bat ky vao day*/
typedef int elementtype;

typedef struct StackRec{
  elementtype storage[MAX];
  int top;
}StackType;

void initialize(StackType *stack){
  (*stack).top = 0;
  //Hoac stack->top = 0;
}

int isEmpty(StackType stack){
  return stack.top == 0;
}

int isFull(StackType stack){
  return stack.top == MAX;
}

void push(elementtype el, StackType *stack){
  if(isFull(*stack)){
    printf("Stack overflow");
  }
  else{
    (*stack).storage[(*stack).top] = el;
    (*stack).top += 1;
  }
}

/*---Ham lay di phan tu top---*/
elementtype pop(StackType *stack){
  if(isEmpty(*stack)){
    printf("Stack underflow");
  }
  else{
    return (*stack).storage[--(*stack).top];
  }
}

/*---Ham chi xem phan tu top ma khong xoa di---*/
elementtype peek(StackType stack){
  if(isEmpty(stack)){
    printf("Stack underflow");
  }
  else{
    return stack.storage[stack.top-1];
  }
}
