/*---Thu vien cho PhoneDB---*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define CONSTANT 100

typedef struct {
  char model[CONSTANT];
  char memory_space[CONSTANT];
  double screen_size;
  double price;
}phone;

typedef struct node_t{
  phone data;
  struct node_t *next;
}node;

node *root, *cur;
node *prev;

node* makeNewNode(phone p){
  node* new = (node*)malloc(sizeof(node));
  new->data = p;
  new->next = NULL;

  return new;
}

/*---Insert new node at any position---*/
node* InsertAtPosition(node* root, phone p, int n /*the position to add new note*/){
  int i;
  node* new;
  new = makeNewNode(p);
  
  cur = root;
  /*---Move CURRENT pointer to the position (n-1)---*/
  for(i = 0; i < n-1; i++){
    cur = cur->next;
  }

  /*---Insert after CURRENT---*/
  new->next = cur->next;
  cur->next = new;
  prev = cur;
  cur = cur->next;

  return new;
}

void insertAfterCurrent(phone p){
  node* new = makeNewNode(p);
  if(root == NULL){
    root = new;
  }
  
  new->next = cur->next;
  cur->next = new;
  prev = cur;
  cur = cur->next;
}

void import_from_dat(FILE* fptr){
  phone *p;

  while((int*)fread(p, sizeof(phone), 1, fptr) != NULL){
    insertAfterCurrent(*p);
  }
}

void displayNode(node* a){
  if(a == NULL)
   {
       printf("Loi con tro NULL\n");
       return ;
   }
   phone tmp = a->data;
   printf("%-25s %-7s %-14.1lf %-16.1lf \n",tmp.model,tmp.memory_space,tmp.screen_size,tmp.price);
}

void traversingList(){
  node* a = root;
  while(a != NULL){
    displayNode(a);
    a = a->next;
  }
}

int main(){
  FILE* fptr;
  fptr = fopen("PhoneDB.dat", "w+b");
  if(fptr == NULL){
    printf("Cannot open PhoneDB.dat\n");
    return 1;
  }

  import_from_dat(fptr);
  traversingList();
}
