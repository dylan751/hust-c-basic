#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct node_type{
  elementType element;
  struct node_type *left, *right;
}nodeType;

typedef nodeType *treeType;//treetype la 1 con tro tro den kieu Node. treeType = Node*

//Ham so sanh 2 phan tu dang elementType bat ky
int compare(elementType a, elementType b){
  if(a > b)
    return 1;
  else if(a < b)
    return -1;
  else return 0;
}

//1. Khoi tao cay rong
void makeNullTree(treeType *T){
  (*T) = NULL;
}

//9. Tao cay tim kiem nhi phan
void insertNode(elementType x, treeType *root){    //Neu truyen vao con tro -> thay doi ca tree. Neu chi truyen vao root bthg -> phai return de lay gia tri
  if(*root == NULL){//Truong hop co so: nut rong
    /*Create a new node for key x*/
    *root = (nodeType*)malloc(sizeof(nodeType));
    (*root)-> element= x;
    (*root)->left = NULL; 
    (*root)->right = NULL;
  }
  else if(compare(x, (*root)->element) < 0)//Neu khoa them vao < khoa nut goc 
    insertNode(x, &(*root)->left);
  
  else if(compare(x, (*root)->element) > 0)
    insertNode(x, &(*root)->right);
}

void LNR(treeType root){
  nodeType* p;
  while(root){
    if((root->left) == NULL){
      printf("%d  ", root->element);
      root = root->right;
    }
    else{
      p = root->left;
      while(p->right && p->right != root){
	p = p->right;
      }
      if(p->right == NULL){
	p->right = root;
	root = root->left;
      }
      else{
	p->right = NULL;//cat duoi
	printf("%d  ", root->element);
	root = root->right;
      }
    }
  }
}

int main(){
  treeType root;
  makeNullTree(&root);
  int arr[10] = {3, 5, 6, 19, 20, 34, 2, 23, 15, 12};

  int i;
  for(i = 0; i < 10; i++){
    insertNode(arr[i], &root);
  }
  printf("Duyet theo thu tu giua: ");
  LNR(root);
  printf("\n");
}
