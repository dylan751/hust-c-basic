#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//THU VIEN DANH CHO CAY BINH THUONG

//typedef ... elementtype;
//Whatever type of element

typedef int elementType;

typedef struct node_type{
  elementType element;
  struct node_type *left, *right;
}nodeType;

typedef nodeType* treeType;//treetype la 1 con tro tro den kieu Node. treeType = Node*

//1. Khoi tao cay rong
void makeNullTree(treeType *T){
  (*T) = NULL;
}

//2. Xem lieu co phai cay rong ko
int isEmptyTree(treeType T){
  return T == NULL;
}

//3. Lay con trai
treeType leftChild(treeType n){
  if(n != NULL) return n->left;
  else return NULL;
}

//4. Lay con phai
treeType rightChild(treeType n){
  if(n != NULL) return n->right;
  else return NULL;
}

//5. Tao ra 1 node moi
nodeType *createNode(elementType newData){
  nodeType *N;
  N = (nodeType*)malloc(sizeof(nodeType));
  if(N != NULL){
    N->left = NULL;
    N->right = NULL;
    N->element = newData;
  }
  return N;
}

//6. Kiem tra co phai La hay k
int isLeaf(treeType n){
  //Neu khong co con trai + con phai -> la Leaf
  if(n != NULL){
    return (leftChild(n) == NULL) && (rightChild(n) == NULL);
  }
  else return -1;
}

//7. Dem so node trong cay
int countNode(treeType T){
  if(isEmptyTree(T)) return 0;
  else return 1 + countNode(leftChild(T)) + countNode(rightChild(T));
}

//8. Tao ra cay nhi phan (Ghep 1 root + 2 cay con = cay moi)
treeType createFrom2(elementType v, treeType l, treeType r){
  treeType N;
  N = (nodeType*)malloc(sizeof(nodeType));

  N->element = v;
  N->left = l;
  N->right = r;
  return N;
}

//9. Them 1 node vao vi tri cuc trai (nut con trai nhat)
treeType addLeft(treeType *tree, elementType newData){
  nodeType *newNode = createNode(newData);
  if(newNode == NULL)
    return newNode;

  if(*tree == NULL){//Neu cay dang empty
    *tree = newNode;
  }
  else{
    nodeType *Lnode = *tree;
    while(Lnode->left != NULL){//Nhay sang trai den khi nao left = NULL -> la nut cuc trai
      Lnode = Lnode->left;
    }
    Lnode->left = newNode;//Gan newNode vao cho leftChild cua node cuc trai
  }
  return newNode;
}

//10. Them 1 node vao vi tri cuc phai (nut con phai nhat)
treeType addRight(treeType *tree, elementType newData){
  nodeType *newNode = createNode(newData);
  if(newNode == NULL)
    return newNode;

  if(*tree == NULL){//Neu cay dang empty
    *tree = newNode;
  }
  else{
    nodeType *Rnode = *tree;//Nut goc
    while(Rnode->right != NULL){//Nhay sang phai den khi nao right = NULL -> la nut cuc phai
      Rnode = Rnode->right;
    }
    Rnode->right = newNode;//Gan newNode vao cho rightChild cua node cuc phai
  }
  return newNode;
}

int max(int a, int b){
  if(a > b)
    return a;
  else return b;
}

//11. Tinh chieu cao cay
int treeHeight(treeType root){
  if(root == NULL)
    return 0;
  else return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}
//12. Tinh so nut la (leaf node)
int leafNode(treeType root){
  if(root == NULL){
    return 0;
  }
  else if(isLeaf(root)){
    return 1;
  }
  else{
    return leafNode(root->left) + leafNode(root->right);
  }
}
//13. Tinh so nut trong
int innerNode(treeType root){
  if(root == NULL){
    return 0;
  }
  if(!isLeaf(root)){
    return 1 + innerNode(root->left) + innerNode(root->right);
  }
  else//Neu la leaf
    return 0;
}

//14. So con phai
int numRight(treeType root){
  if(root == NULL){
    return 0;
  }
  else if(root->right != NULL){
    return 1 + numRight(root->left) + numRight(root->right);
  }
  else /*neu root->right == NULL*/
    return numRight(root->left);
}

//15. Duyet cay theo thu tu giua
void inOrderPrint(treeType root){
  if(root != NULL){
    inOrderPrint(root->left);
    printf("%4d", root->element);
    inOrderPrint(root->right);
  }
}

//16. Ham duyet cay theo thu tu truoc
void preOrderPrint(treeType root){
  if(root != NULL){
    printf("%4d", root->element);
    preOrderPrint(root->left);
    preOrderPrint(root->right);
  }
}

//17. Ham duyet cay theo thu tu sau
void postOrderPrint(treeType root){
  if(root != NULL){
    preOrderPrint(root->left);
    preOrderPrint(root->right);
    printf("%4d", root->element);
  }
}

//18. Ham giai phong toan bo cay
void freeTree(treeType root){
  if(root != NULL){
    freeTree(root->left);
    freeTree(root->right);
    free((void*)root);
  }
}
