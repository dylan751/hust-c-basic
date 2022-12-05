#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct{
  int maSP;
  char ten[40];
  int gia;
  int soLuong;
}elementType;

typedef struct node{
  elementType element;
  struct node *prev;
  struct node *next;
} node;

typedef node* doubleList;

//1. Lay du lieu
elementType getData(){
  elementType new;
  printf("Ma san pham: ");
  scanf("%d", &new.maSP);
  __fpurge(stdin);
  printf("Ten san pham: ");
  scanf("%s", new.ten);
  printf("Gia san pham: ");
  scanf("%d", &new.gia);
  printf("So luong san pham: ");
  scanf("%d", &new.soLuong);

  return new;
}

//2. Tao doublelist rong~
void makeNullList(doubleList* root, doubleList* tail, doubleList* cur){
  *root = NULL;
  *tail = NULL;
  *cur = NULL;
  return;
}

//3. Tao node moi
node *makeNewNode(elementType ele){
  node *new = (node*)malloc(sizeof(node));
  new->element = ele;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

//4. Them 1 phan tu vao cuoi list
void insertAtTail(elementType ele,doubleList *root, doubleList *tail, doubleList *cur){
  node *new = makeNewNode(ele);
  if(*tail == NULL){
    *root = new;
    *tail = new;
    *cur = new;
  }
  else{
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = *tail;
  }
}

//5. Import from .dat
void import(doubleList *r, doubleList *t, doubleList *c){
  int n;
  FILE *f = fopen("PhoneDB.dat", "rb");
  if ((f = fopen("PhoneDB.dat", "rb")) == NULL){
    printf("Khong the mo file PhoneDB.dat!\n");
    return;
  }
  
  fseek(f, 0, SEEK_END);
  n = ftell(f) / sizeof(elementType);//So phan tu
  rewind(f);
  elementType tmp;
  for (int i = 0; i < n; i++){
    fread(&tmp, sizeof(elementType), 1, f);
    insertAtTail(tmp, r, t, c);
  }
  
  printf("\tImported!!!\n");
  fclose(f);
}

//6. Them 1 phan tu vao dau list
void insertAtHead(elementType ele, doubleList *root, doubleList *tail, doubleList *cur){
  node *new = makeNewNode(ele);
  if(*root == NULL){
    *root = new;
    *tail = new;
    *cur = new;
  }
  else{
    (*root)->prev = new;
    new->next = *root;
    new->prev = NULL;
    *root = new;
    *cur = new;
  }
}

//7. Hien thi 1 node
void displayNode(node *p){
  printf("%-5d%-10d%-5d%-20s\n", (p->element).maSP, (p->element).gia, (p->element).soLuong, (p->element).ten);
}

//8. Duyet doubleList tu cuoi list
void traverseListFromTail(node *tail){
  node *p;
  for (p = tail; p != NULL; p = p->prev){
    displayNode(p);
  }
}

//9. Duyet doubleList tu dau list
void traverseListFromRoot(node* root){
  node *p;
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

//10. Them 1 phan tu vao truoc CUR
void insertBeforeCurrent(elementType element, doubleList *root, doubleList *tail, doubleList *cur){
  /* Node tmp = root;
     while(tmp != NULL && tmp->next != cur && cur != NULL)
     {
        tmp = tmp->next;
     }
     prev = tmp;
   */

  node *new = makeNewNode(element);
  if (*root == NULL){
    *tail = new;
    *root = new;
    *cur = new;
  }
  else{
    new->next = *cur;
    if((*cur)->prev != NULL) (*cur)->prev->next = new;
    else *root = new;
    new->prev = NULL;
    (*cur)->prev = new;
    *cur = new;
  }
}

//11. Them 1 phan tu vao sau CUR
void insertAfterCurrent(elementType element, doubleList *root, doubleList *tail, doubleList *cur){
  node *new = makeNewNode(element);
  if (*root == NULL){
    *root = new;
    *tail = new;
    *cur = *root;
  }
  else{
    new->next = (*cur)->next;
    (*cur)->next = new;
    new->prev = (*cur);
    if((*cur)->next != NULL) (*cur)->next->prev = new;
    else *tail = new;
    *cur = new;
  }
}

//12. Xoa phan tu p
void deleteAtPosition(doubleList p, doubleList *root, doubleList *tail, doubleList *cur){
  if(*root == NULL) printf("Empty List!\n");
  else{
    if(p == *root){
      (*root) = (*root)->next;
    }
    
    else p->prev->next = p->next;
    if(p->next != NULL){
      p->next->prev = p->prev;
    }
    else *tail = p->prev;

    free(p);
  }
}

//13. Xoa phan tu dau doubleList
void deleteAtHead(doubleList *root, doubleList *tail, doubleList *cur){
  if(*root == NULL){
    printf("Empty list!\n");
  }
  else{
    *root = (*root)->next;
    (*root)->prev = NULL;
  }
}

//14. Xoa phan tu cuoi doubleList
void deleteAtTail(doubleList *root, doubleList *tail, doubleList *cur){
  if(*root == NULL){
    printf("Empty list!\n");
  }
  else{
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
  }   
}
