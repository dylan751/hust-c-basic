#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct phoneaddress_t{
  
  char name[MAX];
  char tel[MAX];
  char email[MAX];
}phoneaddress;

typedef phoneaddress elementType;

typedef struct node{
  elementType element;
  struct node *left, *right;
}nodeType;

typedef nodeType* treeType;

int compare(char* a, char* b){
  if(strcmp(a, b) > 0)
    return 1;
  else if(strcmp(a, b) < 0)
    return -1;
  else return 0;
}

treeType search(char* email, treeType root){
  if(root == NULL)
    return NULL;
  else if(strcmp((root->element).email, email) ==0)//Found
    return root;
  else if(strcmp((root->element).email, email) < 0)//Continue searching in the right sub tree
    return search(email, root->right);
  else{//Continue searching in the left sub tree
    return search(email, root->left);
  }
}

void insertNode(elementType x, treeType *root){
  if(*root == NULL){
    *root = (nodeType*)malloc(sizeof(nodeType));
    (*root)->element = x;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if(strcmp(x.email, (*root)->element.email) < 0){
    insertNode(x, &(*root)->left);
  }
  else insertNode(x, &(*root)->right);
}

void inOrderPrint(treeType root){
  if(root != NULL){
    inOrderPrint(root->left);
    inOrderPrint(root->right);
    printf("%25s%25s%25s\n", root->element.name, root->element.tel, root->element.email);
  }
}

elementType deleteMin(treeType *root){
  elementType k;
  if((*root)->left == NULL){
    k = (*root)->element;
    (*root) = (*root)->right;
    return k;
  }
  else return deleteMin(&(*root)->left);
}

void deleteNode(char* x, treeType *root){
  if(*root != NULL){
    if(compare(x, (*root)->element.email) < 0){
      deleteNode(x, &(*root)->left);
    }
    else if(compare(x, (*root)->element.email) > 0){
      deleteNode(x, &(*root)->right);
    }
    else if((*root)->left == NULL && (*root)->right == NULL){
      *root = NULL;//Truong hop la node leaf -> xoa luon
    }
    else if((*root)->left == NULL){//Neu chi co 1 con phai->cha tro den thang con phai cua con
      *root = (*root)->right;
    }
    else if((*root)->right == NULL){//Neu chi co 1 con trai
      *root = (*root)->left;
    }
    else //Copy gia tri cua node cuc trai cua cay con phai cho gia tri cua root
      (*root)->element = deleteMin(&(*root)->right);
  }
}

int main(){
  FILE* fptr;
  elementType phonearr[MAX];
  elementType *temp = (elementType*)malloc(sizeof(elementType));
  treeType root;
  char* key = (char*)malloc(sizeof(char));
  int i = 0, n = 10;//return code

  //Read from this file to array
  if((fptr = fopen("phonebook.dat", "rb")) == NULL){
    printf("Cannot open file phonebook.dat\n");
    return -1;
  }
  else{
    while((elementType*)fread(temp, sizeof(elementType), 1, fptr) != NULL){
      phonearr[i] = *temp;
      i++;
    }
  }
  for(i = 0; i < n; i++){
    insertNode(phonearr[i], &root);
  }
  inOrderPrint(root);

  printf("Input the email you want to search: ");
  scanf("%[^\n]s", key);
  if(search(key, root) != NULL)
    printf("%25s%25s%25s\n", search(key, root)->element.name, search(key, root)->element.tel, search(key, root)->element.email);
  else
    printf("Cannot find the email you want!\n");

  //Xoa node nhap vao
  deleteNode(key, &root);
  inOrderPrint(root);
  
  free(temp);
  free(key);
  fclose(fptr);
}

