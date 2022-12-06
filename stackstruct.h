#include <stdio.h>
#define MAX 50

typedef int Eltype;
typedef struct
{
    Eltype data[MAX];
    int top;
} Stack;


void initialize(Stack *stack);
int isEmpty(Stack stack);
int isFull(Stack stack);
void push(Eltype el,Stack *stack);
Eltype pop(Stack *stack);
Eltype peek(Stack stack);


void initialize(Stack *stack)
{
    stack->top = 0;
    return;
}

int isEmpty(Stack stack)
{
    return stack.top == 0;
}

int isFull(Stack stack)
{
    return stack.top == MAX;
}

void push(Eltype el,Stack *stack)
{
    if(isFull(*stack))
    {
        printf("Stack over flow!\n");
        return;
    }
    else
    {
        stack->data[stack->top++] = el;
    }

    return;
}

Eltype pop(Stack *stack)
{
    return stack->data[--stack->top];
}

Eltype peek(Stack stack)
{
    if(isEmpty(stack))
    {
        perror("Stack under flow!\n");
        return 1;
    }
    else
    {
        return stack.data[stack.top-1];
    }
}
