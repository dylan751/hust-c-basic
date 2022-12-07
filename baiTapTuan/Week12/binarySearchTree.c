#include<stdio.h>
#include"binarySearchTree.h"
#include<time.h>

int main(){
  int arr[10];
  int i;
  srand(time(NULL));
  
  for(i = 0; i < 10; i++){
    arr[i] = rand()%100;
  }
  treeType root;

  makeNullTree(&root);
  for(i = 0; i < 10; i++){
    insertNode(arr[i], &root);
  }

  printf("Before delete: ");
  inOrderPrint(root);
  printf("\n");
  printf("arr[4] = %d\n", arr[4]);
  deleteNode(arr[4], &root);

  printf("After delete arr[4]: ");
  inOrderPrint(root);
  printf("\n");

  printf("Max = %d\nMin = %d\n", findMax(root), findMin(root));
}
