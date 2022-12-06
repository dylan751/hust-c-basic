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

int Empty_Queue(Queue Q){
  return Q.front == -1;
}

int Full_Queue(Queue Q){
  return (Q.rear-Q.front+1) == MAX;
}

void EnQueue(elementtype X, Queue *Q){
  if(!Full_Queue(*Q)){
    if(Empty_Queue(*Q)){
      Q->front = 0;//Phan tu dau la A[0]
    }
    Q->rear = Q->rear + 1;
    Q->element[Q->rear] = X;
  }
  else printf("Queue is full!");
}


elementtype DeQueue(Queue *Q){
  if(!Empty_Queue(*Q)){
    Q->front = Q->front+1;

    if(Q->front > Q->rear){//Neu Queue rong~
      MakeNull_Queue(&(*Q));//Queue become empty
    }
  }
  else printf("Queue is empty!");
}

