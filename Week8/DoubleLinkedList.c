#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define CONSTANT 100
//typedef ... elementtype;

typedef struct {
  char model[CONSTANT];
   char memory[CONSTANT];
   double size;
   double price;
}elementtype;

typedef struct node{
  elementtype element;
  struct node* prev;
  struct node* next;
}node;

node* head, tail, cur;

/*---Ham tao danh sach moc noi kep rong---*/
void makeNull_List(node** root, node** tail,node** cur){
  (*root) = NULL;
  (*tail) = NULL;
  (*cur) = NULL;
}

/*---Kiem tra xem danh sach co rong hay khong---*/
int isEmpty(node* root){
  return (root == NULL);
}

/*---Tao node moi cho danh sach 2 chieu---*/
node* makeNewNode(elementtype ele){
  node* new = (node*)malloc(sizeof(node));
  new->element = ele;
  new->next = NULL;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void insertAtHead(elementtype e, node** root, node** tail, node** cur){
   node* new = makeNewNode(e);
   if(*root == NULL){
     *root = new;
     *tail = new;
     *cur = new;
   }

   new->next = *root;
   (*root)->prev = new;
   *root = new;
   *cur = *root;
}

void insertAfterCurrent(elementtype e, node** root, node** tail, node** cur){
  node* new = makeNewNode(e);
  if(*root == NULL){
    /*If there is no element*/
    *root = new;
    *tail = new;
    *cur = *root;
  }
  else{
    new->next = (*cur)->next;
    if((*cur)->next != NULL){
      (*cur)->next->prev = new;
    }
    else *tail = new;
    (*cur)->next = new;
    new->prev = *cur;
    *cur = new;
  }
}

void Delete_List(node* p, node** root, node** tail, node** cur){
  if(*root == NULL){
    printf("Empty list!");
  }
  else{
    if(p == *root){
      /*Delete first element*/
      (*root) = (*root)->next;
    }
    else p->next->next = p->next;
    if(p->next != NULL){
      p->next->prev = p->prev;
    }
    else{//p is tail
      *tail = p->prev;
    }
    *cur = p->prev;
    free(p);
  }
}

void displayNode(node* p){
  if(p == NULL){
    printf("Loi con tro!\n");
    return;
  }
  elementtype tmp = p->element;
  printf("%-25s %-7s %-14.1lf %-16.1lf \n",tmp.model,tmp.memory,tmp.size,tmp.price);
}

void traverseList(node** root, node** tail, node** cur){
  node *p;
  for(p = *root; p != NULL; p = p->next){
    displayNode(p);
  }
}

void read(elementtype data){
  __fpurge(stdin);
  printf("Model: ");
  scanf("%[^\n]s", data.model);

  __fpurge(stdin);
  printf("Memory: ");
  scanf("%[^\n]s", data.memory);

  printf("Size: ");
  scanf("%lf", &data.size);

  printf("Price: ");
  scanf("%lf", &data.price);
}

/*---Phai nang cap cho phien ban double linked list (day moi la ban single linked list)(dang su dung bien toan cuc -> phai sua lai)---*/
/*
void insertAtPosition(elementtype e, int position){
  cur = root;
  int i;
  if(position <= 0){
    insertBeforeCurrent(e);
    return;
  }
  //move pointer to node at position
  for(i = 1; i < positon; i++){
    if(cur->next != NULL){
      cur = cur->next'
    }
  }
  insertAfterCurrent(e);
}
*/

/*---Phai nang cap cho phien ban double linked list (day moi la ban single linked list) (dang su dung bien toan cuc -> phai sua lai)---*/
/*
void deleteAtPosition(int position){
  cur = root;
  int i;
  for(i = 0; i < position; i++){
    if(cur->next != NULL){
      prev = cur;
      cur = cur->next;
    }
    else break;
  }

  if(i < position || position < 0){
    printf("There is no node at position %d.\n", position);
    return;
  }
  deleteCurrentElement();
}
*/

/*---Dang su dung bien toan cuc -> phai sua lai---*/
/*
void append(elementtype e){//Insert At Tail
  node* new = makeNewNode(e);
  if(tail == NULL){
    root = new;
    tail = new;
    cur = new;
    return;
  }
  tail->next = new;
  new->prev = tail;
  tail = new;
  cur = tail;
}
*/

int main(){
  node *root, *cur, *tail;
  node* a;
  int i;
  elementtype data[CONSTANT];

  makeNull_List(&root, &tail, &cur);
  for(i = 0; i < 2; i++){
    read(data[i]);
    a = makeNewNode(data[i]);
  }

  traverseList(&root, &tail, &cur);
 
}
