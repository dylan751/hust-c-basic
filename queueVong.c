#include<stdio.h>
#include"QueueVong.h"
/*
int main(){
  int i, a;
  elementtype A[10];
  elementtype x;

  Queue Q;
  MakeNull_Queue(&Q);
  for(i = 0; i < 10; i++){
    printf("A[%d]: ", i);
    scanf("%d", &A[i]);
  }
  for(i = 0; i < 10; i++){
    EnQueue(A[i], &Q);
  }
  
  printf("Input a number: ");
  scanf("%d", &a);
  if(Full_Queue){//Neu Queue full -> lay phan tu dau, them 1 phan tu vao duoi -> in ra phan tu dau
    x = DeQueue(&Q);
    EnQueue(a, &Q);
  }
  printf("Removed integer: %d\n", x);
}
*/

int main(){
  Queue q;
  char c = 'y';
  int element, count = 0;
  MakeNull_Queue(&q);
  EnQueue(10, &q);
  printf("--A series of Enqueue and Dequeue operation-\n");
  while(!Full_Queue(q) && c != 'n'){
    printf("%d. Enter a number to enqueue: ", count+1);
    scanf("%d", &element);
    EnQueue(element, &q);
    if(!isEmptyQueue(q)){
      element = DeQueue(&q);
      printf("Dequeue element %d\n", element);
    }
    count++;
    printf("Continue? (y/n): ");
    while(getchar() != '\n'){
      c = getchar();
    }
  }
  //printf("Queue is full\n\n");
  return 0;
}
