/*---Chuong trinh mau cho cac ham ve linked list---*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

/*---Declaration of address list---*/
typedef struct address_t {
  char name[20];
  char tel[11];
  char email[25];
}address;

typedef struct list_el{
  address addr;
  struct list_el *next;
}node_addr;


/*---Initialisation---*/
node_addr *root, *cur;
node_addr *prev;

/*---Make new node---*/
node_addr* makeNewNode(address addr){
  node_addr* new = (node_addr*)malloc(sizeof(node_addr));
  new->addr = addr;
  new->next = NULL;

  return new;
}

/*---Ham nhap du lieu vao---*/
address readNode(){
  address tmp;
  __fpurge(stdin);
  printf("Input name: ");
  scanf("%[^\n]s", tmp.name);
  __fpurge(stdin);
  printf("Input telephone number: ");
  scanf("%[^\n]s", tmp.tel);
  __fpurge(stdin);
  printf("Input email: ");
  scanf("%[^\n]s", tmp.email);

  return tmp;
}

/*---display name, tel, email in columns---*/
address displayNode(node_addr *p){
  address tmp = p->addr;
  if(p == NULL){
    printf("Loi con tro NULL\n");
    return tmp;
  }

  printf("%-20s\t%-15s\t%-30s %p\n", tmp.name, tmp.tel, tmp.email, p->next);
}

/*---Ham them 1 ban ghi da co san---*/
void insertAtHead(address addr){
  node_addr* new = makeNewNode(addr);
  new->next = root;
  root = new;
  cur = root;
}

/*Ham chen 1 node moi vao sau con tro current*/
void insertAfterCurrent(address addr){
  node_addr* new = makeNewNode(addr);
  if(root == NULL){
    /*if there is no element*/
    root = new;
    cur = root;
  }
  else if(cur == NULL){
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
void insertBeforeCurrent(address addr){
  /*Gan con tro PREV vao vi tri truoc CUR neu PREV chua duoc khoi tao dung truoc con tro CUR*/
  /*node_addr* tmp;
  tmp = root;
  while(tmp != NULL && tmp->next != cur && cur != NULL){
    tmp = tmp->next;
  }
  prev = tmp;// -> prev tro toi truoc con tro cur*/

  node_addr* new = makeNewNode(addr);
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
  node_addr *p;
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

/*---Xoa node dau tien trong danh sach---*/
void deleteFirstElement(){
  node_addr *del;//Bien de xoa
  
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
  node_addr *to_free;

  to_free = root;
  while(to_free != NULL){
    root = root->next;
    free(to_free);
    to_free = root;
  }
}

/*---Dao nguoc linked list---*/
node_addr* reverseList(node_addr* root){
  node_addr *now, *before;//Giong con tro current va previous
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
