#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//typedef ... elementtype;
typedef int elementtype;

typedef struct Node{
  elementtype element;
  struct Node* next;
};

typedef Node* Position;
typedef struct{
  Postition front, rear;
}Queue;

void MakeNull_Queue(Queue *Q){
  Q->front = NULL;
  Q->rear = NULL;
}

int isEmptyQueue(Queue Q){
  return (Q.front == Q.rear);
}

//Con 1 truong hop: Neu Queue rong~ -> code nay chua khoi tao gia tri cho front
void EnQueue(elementtype X, Queue *Q){
  Node* new = (Node*)malloc(sizeof(Node));
  if(Q->front == NULL){//Neu rong, thi them 1 phan tu vao danh sach
    Q->front = new;
    Q->rear = new;
  }
  else{
    Q->rear->next = new;
    Q->rear = Q->rear->next;
  }
  Q->rear->element = X;
}

elementtype DeQueue(Queue *Q){
  if(!isEmptyQueue(Q)){
    Position T;
    T = Q->front;
    Q->front = Q->front->next;
    free(T);
  }
  else{
    printf("Error: Queue is empty.");
  }
}
