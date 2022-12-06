#include<stdio.h>
//include"binarySearchTree.h"
#include"binaryTree.h"
void InsertNode(elementType x,treeType *Root ){
  if (*Root == NULL){/* Create a new node for key x */
    *Root=(nodeType*)malloc(sizeof(nodeType));
    (*Root)->element = x;
    (*Root)->left = NULL;
    (*Root)->right = NULL;
  } else if (x < (*Root)->element)
    InsertNode(x, &(*Root)->left);
  else if (x > (*Root)->element)
    InsertNode(x, &(*Root)->right);
}

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
  addRight(&root->left, 0);
  addRight(&root->left, 1);
  addRight(&root->left->left, 0);
  addRight(&root->left->left, 1);
  printf("Duyet cay truoc khi xoa: ");
  inOrderPrint(root);
  
  printf("The height of the tree: %d\n"
         "The number of leafs: %d\n"
	 "The number of internal nodes: %d\n"
	 "The number of right children: %d\n", treeHeight(root), leafNode(root), innerNode(root), numRight(root));

  deleteNode(10, &root);
  printf("Duyet cay sau khi xoa: ");
  inOrderPrint(root);
  
  return 0;
}
