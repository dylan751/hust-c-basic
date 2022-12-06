#include<stdio.h>
#include"binaryTree.h"

int main(){
  treeType T;

  makeNullTree(&T);
  int i, n;
  int A[100];

  for(i = 0; i < 5; i++){
    printf("A[%d]: ", i);
    scanf("%d", &A[i]);
  }
  
  printf("Count = %d\n", countNode(T));
}
