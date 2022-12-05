#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

#define CONSTANT 100


typedef struct {
  char model[30];
  double memory_space;
  double screen_size;
  double price;
}phone;

typedef struct list_el{
  phone addr;
  struct list_el *next;
}node_phone;


/*---Initialisation---*/
node_phone *root, *cur;
node_phone *prev;

/*---Make new node---*/
node_phone* makeNewNode(phone addr){
  node_phone* new = (node_phone*)malloc(sizeof(node_phone));
  new->addr = addr;
  new->next = NULL;

  return new;
}

/*---Ham them 1 ban ghi da co san---*/
void insertAtHead(phone addr){
  node_phone* new = makeNewNode(addr);
  new->next = root;
  root = new;
  cur = root;
}

/*Ham chen 1 node moi vao sau con tro current*/
void insertAfterCurrent(phone addr){
  node_phone* new = makeNewNode(addr);
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
void insertBeforeCurrent(phone addr){
  /*Gan con tro PREV vao vi tri truoc CUR neu PREV chua duoc khoi tao dung truoc con tro CUR*/
  /*node_addr* tmp;
  tmp = root;
  while(tmp != NULL && tmp->next != cur && cur != NULL){
    tmp = tmp->next;
  }
  prev = tmp;// -> prev tro toi truoc con tro cur*/

  node_phone* new = makeNewNode(addr);
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

/*---display 1 node---*/
phone displayNode(node_phone *p){
  phone tmp = p->addr;
  if(p == NULL){
    printf("Loi con tro NULL\n");
    return tmp;
  }

  printf("%-20s\t%-15.2lf\t%-30.2lf %-15.2lf\n", tmp.model, tmp.memory_space, tmp.screen_size, tmp.price);
}

void import_from_text(FILE *fptr, phone phone){
  while(fscanf(fptr, "%s %lf %lf %lf", phone.model, &phone.memory_space, &phone.screen_size, &phone.price) != EOF){
    insertAtHead(phone);
  }
}

void import_from_dat(FILE *fptr){
  phone *phonearr, p;
  
  while((int*)fread(phonearr, sizeof(phone), 1, fptr) != NULL){
    p = *phonearr;
    insertAfterCurrent(p);
  }
}

/*---Display all nodes---*/
void traversingList(){
  node_phone *p;
  printf("%-20s\t%-14s\t%-32s%-14s\n", "Model", "Memory space", "Screen size", "Price");
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

void search_by_model(){\
  char find[CONSTANT];
  int mark = 1;//Check if can find or not
  printf("Input the model that you want to find: ");
  scanf("%s", find);

  node_phone *p;

  printf("---Result---\n");
  printf("%-20s\t%-17s\t%-32s %-17s\n", "Model", "Memory space", "Screen size", "Price");
  for(p = root; p != NULL; p = p->next){
    if(strcmp(find, (p->addr).model) == 0){
      displayNode(p);
      mark = 0;//Phone model found
    }
  }

  if(mark == 1){
    printf("There aren't any phone model suit your needs!\n");
  }
}

void search_by_price(){
  double find;
  node_phone *p;
  int mark = 1;//Check if there are phone or not
  printf("Input the maximum price you can afford: ");
  scanf("%lf", &find);

  while(find < 0){
    printf("Price must be >0! Input again: ");
    scanf("%lf", &find);
  }

  printf("---Result---\n");
  printf("%-20s\t%-17s\t%-32s %-17s\n", "Model", "Memory space", "Screen size", "Price");
  for(p = root; p != NULL; p = p->next){
    if((p->addr).price < find){
      displayNode(p);
      mark = 0; //found some phones
    }
  }

  if(mark == 1){
    printf("There aren't any phone that cheaper than your needs!\n");
  }
}

void export_to_dat(FILE *fptr){
  node_phone *p;
  p = root;
  phone *phonearr;

  while(p != NULL){
    strcpy(phonearr->model, p->addr.model);
    phonearr->memory_space = p->addr.memory_space;
    phonearr->screen_size = p->addr.screen_size;
    phonearr->price = p->addr.price;

    fwrite(phonearr, sizeof(phone), 1, fptr);
    p = p->next;
  }
}

phone input_phone(){
  phone p;
  __fpurge(stdin);
  printf("Phone model: ");
  scanf("%[^\n]s", p.model);
  
  printf("Memory space: ");
  scanf("%lf", &p.memory_space);
  while(p.memory_space < 0){
    printf("Must be > 0! Input again: ");
    scanf("%lf", &p.memory_space);
  }
  
  printf("Screen size: ");
  scanf("%lf", &p.screen_size);
  while(p.screen_size < 0){
    printf("Must be > 0! Input again: ");
    scanf("%lf", &p.screen_size);
  }
  
  printf("Price: ");
  scanf("%lf", &p.price);
  while(p.price < 0){
    printf("Must be > 0! Input again: ");
    scanf("%lf", &p.price);
  }

  return p;
}

void manual_insertion(){
  char choice = 0;
  phone p;
  while(choice != '3'){
    printf("                ---Menu---\n"
	   "|1. Input one new model BEFORE current node.|\n"
	   "|2. Input one new model AFTER current node .|\n"
	   "|3. Exit.                                   |\n");
    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice < '1' || choice > '3'){
      __fpurge(stdin);
      printf("Choice must be from 1->3! Input again: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1': {
      p = input_phone();
      insertBeforeCurrent(p);
      break;
    }

    case '2': {
      p = input_phone();
      insertAfterCurrent(p);
      break;
    }
    }
  }
  
}

/*---Xoa toan bo node trong danh sach---*/
void deleteAllNode(){
  node_phone *to_free;

  to_free = root;
  while(to_free != NULL){
    root = root->next;
    free(to_free);
    to_free = root;
  }
}

int main(){
  char choice = '0';
  phone phone;
  FILE* fptr_text = fopen("PhoneDB.txt", "r");;
  if(fptr_text == NULL){
    printf("Cannot open %s", "PhoneDB.txt");
    return 1;
  }

  FILE* fptr_dat = fopen("PhoneDB.dat", "w+b");;
  if(fptr_dat == NULL){
    printf("Cannot open %s", "PhoneDB.dat");
    return 1;
  }
    
  while(choice != '8'){
    __fpurge(stdin);
    printf("                      -------Menu-------                    \n"
	   "|1. Import from Text.                                       |\n"
	   "|2. Import from Dat.                                        |\n"
	   "|3. Display List.                                           |\n"
	   "|4. Search phone by Model.                                  |\n"
	   "|5. Search phone that the price is under the value inputted.|\n"
	   "|6. Export to Dat.                                          |\n"
	   "|7. Manual Insertion.                                       |\n"
	   "|8. Quit.                                                   |\n");
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice < '1' || choice > '8'){
      printf("Choice must be from 1->8! Input again: ");
      __fpurge(stdin);
      scanf("%c", &choice);
    }
    switch(choice){
    case '1': {
      import_from_text(fptr_text, phone);
      break;
    }
      
    case '2': {
      
      import_from_dat(fptr_dat);
      break;
    }
      
    case '3': {
      traversingList();
      break;
    }

    case '4': {
      search_by_model();
      break;
    }
      
    case '5': {
      search_by_price();
      break;
    }
      
    case '6': {
      export_to_dat(fptr_dat);
      break;
    }
      
    case '7': {
      manual_insertion();
      break;
    }
      
    }

  }

  fclose(fptr_text);
  fclose(fptr_dat);
}
