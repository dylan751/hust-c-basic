/*---Chuong trinh ap dung cho struct bat ky---*/
/*---Nhap struct ban muon vao "..."  ---*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define CONSTANT 100
typedef struct {
 char model[CONSTANT];
 char memory[CONSTANT];
 double size;
 double price ;
}elementtype;

struct node_t{
  elementtype element;
  struct node_t *next;
};
typedef struct node_t node;


/*---Initialisation---*/
node *root, *cur;
node *prev;

/*---Make new node---*/
node* makeNewNode(elementtype el){
  node* new = (node*)malloc(sizeof(node));
  new->element = el;
  new->next = NULL;

  return new;
}

/*---Ham nhap du lieu vao---*/
elementtype readNode(){
  elementtype tmp;
  __fpurge(stdin);
  printf("Input model: ");
  scanf("%[^\n]s", tmp.model);
  __fpurge(stdin);
  printf("Input memory: ");
  scanf("%[^\n]s", tmp.memory);
  __fpurge(stdin);
  printf("Input size: ");
  scanf("%lf", &tmp.size);
  printf("Input price: ");
  scanf("%lf", &tmp.price);
  
  return tmp;
}

/*---display name, tel, email in columns---*/
elementtype displayNode(node *p){
  elementtype tmp = p->element;
  if(p == NULL){
    printf("Loi con tro NULL\n");
    return tmp;
  }

  printf("%-20s\t%-15s\t%-10.2lf\t%-10.2lf\n", tmp.model, tmp.memory, tmp.size, tmp.price);
}

/*---Ham them 1 ban ghi da co san---*/
void insertAtHead(elementtype el){
  node* new = makeNewNode(el);
  new->next = root;
  root = new;
  cur = root;
}

/*Ham chen 1 node moi vao sau con tro current*/
void insertAfterCurrent(elementtype el){
  node* new = makeNewNode(el);
  if(root == NULL){
    /*if there is no element*/
    root = new;
    cur = root;
  }
  else if(cur == NULL){
    printf("Current pointer is NULL\n");
    return;
  }
  else{
    new->next = cur->next;
    cur->next = new;
    prev = cur; /*(neu muon de con tro prev luon dung truoc con tro cur) -> nen dung*/
    cur = cur->next;
    }
}

/*Ham chen 1 node moi vao truoc con tro current*/
void insertBeforeCurrent(elementtype el){
  /*Gan con tro PREV vao vi tri truoc CUR neu PREV chua duoc khoi tao dung truoc con tro CUR*/
  /*node* tmp;
  tmp = root;
  while(tmp != NULL && tmp->next != cur && cur != NULL){
    tmp = tmp->next;
  }
  prev = tmp;// -> prev tro toi truoc con tro cur*/

  node* new = makeNewNode(el);
  if(root == NULL){
    /*If there is no element*/
    root = new;
    cur = root;
  }else{
    new->next = cur;
    /*if cur pointed to first element*/
    if(cur == root){
      /*Nut moi them vao tro thanh dau danh sach*/
      root = new;
    }
    else{
      prev->next = new;
    }
    cur = new;
  }
}

/*---Duyet toan bo danh sach---*/
void traversingList(){
  node *p;
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

/*---Xoa node dau tien trong danh sach---*/
void deleteFirstElement(){
  node *del;//Bien de xoa
  
  del = root;
  if(del == NULL) return;
  
  root = del->next;
  free(del);
  cur = root;
  prev = NULL;
}

/*---Xoa node Current trong danh sach*/
void deleteCurrentElement(){
  if(cur == NULL) return;

  if(cur == root){
    deleteFirstElement();
  }
  else{
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
  }
}

void deleteAllNode(){
  node *to_free;

  to_free = root;
  while(to_free != NULL){
    root = root->next;
    free(to_free);
    to_free = root;
  }
}

/*---Dao nguoc linked list---*/
node* reverseList(node* root){
  node *now, *before;//Giong con tro current va previous
  now = NULL;
  before = NULL;

  while(root != NULL){
    now = root;
    root = root->next;
    now->next = before;
    before = now;
  }

  return before;
  }

