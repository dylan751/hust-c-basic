#include<stdio.h>
#define MAX 100

//typedef ... elementtype;

typedef int elementtype;
typedef struct {
  elementtype element[MAX]; //Store the elements
  int front, rear;
} Queue;

void MakeNull_Queue(Queue *Q){
  Q->front = -1;
  Q->rear = -1;
}

int isEmptyQueue(Queue Q){
  return Q.front == -1;
}

int Full_Queue(Queue Q){
  return (Q.rear-Q.front+1) % MAX == 0;
}

elementtype DeQueue(Queue *Q){
  elementtype e;
  if(!isEmptyQueue(*Q)){
    //if queue contain only one element
    e = Q->element[Q->front];
    if(Q->front == Q->rear){
      MakeNull_Queue(Q);
    }
    else{
      Q->front = (Q->front+1) % MAX;
    }
    return e;
  }
  else printf("Queue is empty!");
}

void EnQueue(elementtype X, Queue *Q){
  if(!Full_Queue(*Q)){
    if(isEmptyQueue(*Q)){
      Q->front = 0;
    }
    Q->rear = (Q->rear+1) % MAX;
    Q->element[Q->rear] = X;
  }
  else{
    printf("Queue is full!");
  }
}
