#include<stdio.h>
#include"binaryTree.h"

int main(){
  int i;
  treeType root = (nodeType*)malloc(sizeof(nodeType));
  makeNullTree(&root);
  for(i = 0; i < 6; i++){
    addRight(&root, i);
  }
  for(i = 0; i < 3; i++){
    addLeft(&root, i);
  }
  addRight(&root->left, 2);
  addRight(&root->left, 3);
  addRight(&root->left->left, 10);
  addRight(&root->left->left, -2);

  printf("The height of the tree: %d\n"
         "The number of leafs: %d\n"
	 "The number of internal nodes: %d\n"
	 "The number of right children: %d\n", treeHeight(root), leafNode(root), innerNode(root), numRight(root));
  
  return 0;
}
