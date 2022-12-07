#include<stdio.h>
#include"binarySearchTree.h"

int main(){
  int a[10] = {1, 2, 3, 5, 7, 4, 11, 10, 13, 21};
  int i;

  treeType root;
  makeNullTree(&root);
  for(i = 0; i < 10; i++){
    insertNode(a[i], &root);
    //inOrderPrint(root); Ham duyet cay
  }
  return 0;
}
