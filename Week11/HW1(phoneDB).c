#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include"DoubleLinkedList.h"
#define CONSTANT 100
 
elementtype input_phone(){
  __fpurge(stdin);
  elementtype p;
  printf("Input Model :__");
  scanf("%s",p.model);
  __fpurge(stdin);
  printf("Phone memory :__");
   scanf("%s", p.memory);
   __fpurge(stdin);
   printf("Screen size:__");
   scanf("%lf", &p.size);
   while(p.size < 0) {
     __fpurge(stdin);
     printf("Error! the size must be > 0! Input again: ");
     scanf("%lf", &p.size);
   }
   
   printf("Phone price:__");
   scanf("%lf", &p.price);
   __fpurge(stdin);
   while(p.price < 0){
     __fpurge(stdin);
     printf("Error! the price must be > 0! Input again: ");
     scanf("%lf", &p.price);
   }
   return p;
}
 
void so1(FILE*input1){
  elementtype *m,p;
 
  while((int*)fread(m,sizeof(elementtype),1,input1)!=NULL){
    p=*m;
    // append(p);
    AddtoTail(p);
  }
  
}

/*---Neu tim duoc -> dua phan tu key len dau danh sach---*/
void moveToFront(){
  node* p = root;
  char* k = (char*)malloc(sizeof(char));
  if(k == NULL){
    printf("Allocation failed!\n");
    return;
  }

  int mark = 0;
  
  printf("Enter the phone model you want to find: ");
  scanf("%s", k);
  
  if(strcasecmp(root->element.model, k) == 0){//Neu root la cai can tim
    displayNode(p);
    return;
  }
     
  while(p != NULL){
    if(strcasecmp(p->element.model, k) == 0){
      if(p->next == NULL){//Neu phan tu can tim nam o cuoi linkedList
	displayNode(p);
	p->prev->next = NULL;
	p->next = root;
	p->prev = NULL;
	root = p;
	return;
      }
      displayNode(p);
      mark++;
      
      //Code dua node tim duoc len vi tri dau
      p->prev->next = p->next;
      p->next->prev = p->prev;
      p->prev = NULL;
      p->next = root;
      root->prev = p;
      root = p;
      return;
    }
    p = p->next;
  }
  if(mark == 0)
    printf("Can't find the phone model you want!\n");
  free(k);
}

/*---Neu tim duoc -> doi cho phan tu key voi phan tu dung truoc---*/
void tranpose(){
  elementtype tmp;
  node* p = root;
  char* k = (char*)malloc(sizeof(char));
  if(k == NULL){
    printf("Allocation failed!\n");
    return;
  }

  int mark = 0;
  
  printf("Enter the phone model you want to find: ");
  scanf("%s", k);
  
  if(strcasecmp(root->element.model, k) == 0){//Neu root la cai can tim-> chi can in ra
    displayNode(p);
    return;
  }
     
  while(p != NULL){
    if(strcasecmp(p->element.model, k) == 0){
      displayNode(p);
      mark++;

      //Code dao gia tri cua node tim duoc voi vi tri truoc no
      tmp = p->element;
      p->element = p->prev->element;
      p->prev->element = tmp;
      return;
    }
    p = p->next;
  }
  if(mark == 0)
    printf("Can't find the phone model you want!\n");
  free(k);
}

void search(){
  int choice = 0;
  while(choice != 4){
    printf("|1. Normal search.        |\n"
	   "|2. Move to front search. |\n"
	   "|3. Transpose search.     |\n"
	   "|4. Exit.                 |\n");
    printf("Input your choice: ");
    scanf("%d", &choice);
    while(choice < 1 || choice > 4){
      printf("Invalid! Input again: ");
      scanf("%d", &choice);
    }

    switch(choice){
    case 1:{
      node*p;
      char*k=(char*)malloc(sizeof(char));
      int i=0;
      printf("Enter the phone model u wanna find :");
      scanf("%s",k);
      p=root;
      while(p!=NULL)
	{
	  if(strcasecmp(p->element.model,k)==0)
	    {
	      displayNode(p);
	      i++;
	    }
	  p=p->next;
	}
      if(i==0)
	printf("Can't find the phone model u need !\n");
      free(k);
      break;
    }
      
    case 2:{
      moveToFront();
      break;
    }
      
    case 3:{
      tranpose();
      break;
    }
    }
  }
   
}

void exporttodat(){
  FILE*output=fopen("PhoneDB.dat","wb");
  node*p;
  p=root;
  elementtype*m;
  while(p!=NULL){
    strcpy(m->model,p->element.model);
    strcpy(m->memory,p->element.memory);
    m->price=p->element.price;
    m->size=p->element.size;
    fwrite(m,sizeof(elementtype),1,output);
    p=p->next;
  }
  
  fclose(output);
}

void ManualInsertion(){
   int choice;
   elementtype p;
   while(choice != 5){
     printf("                ---Menu---\n"
	    "|1. Input one new model BEFORE current node.  |\n"
	    "|2. Input one new model AFTER current node .  |\n"
	    "|3. Input one new model AT FIRST node .       |\n"
	    "|4. Input one new model AT LAST node (append).|\n"
	    "|5. Exit.                                     |\n");
     printf("Input your choice: ");
     scanf("%d", &choice);
     switch(choice){
     case 1 :{
       p=input_phone();
       insertBeforeCurrent(p);
       break;
     }
     case 2 :{
       p=input_phone();
       insertAfterCurrent(p);
       break;
     }
     case 3 :{
       p=input_phone();
       AddtoHead(p);
       break;
     }
     case 4 :{
       p=input_phone();
       AddtoTail(p);
       break;
     }
     case 5 :{
       printf("\nExit now !");
       break;
     }
     }
   }
}
int main(){
  FILE *input1, *output;
  node *r;
  input1 = fopen("PhoneDB.dat","rb");
  if(input == NULL){
    printf("No such file or directory !");
    return 0;
  }
  int n1,n2;//dung cho menu 10
  int i;
  int x;
  int m, n = 0;
  elementtype p;
  while(m != 12){
    printf("            ---Menu---\n"
	   "|1.Import Database from .dat file.       |\n"
	   "|2.Print all Database.                   |\n"
	   "|3.Manual Insertion.                     |\n"
	   "|4.InsertAtPosition.                     |\n"
	   "|5.DeleteAtPosition.                     |\n"
	   "|6.DeleteAtFirst.                        |\n"
	   "|7.DeleteAtCurrent.                      |\n"
	   "|8.Delete last.                          |\n"
	   "|9.Search for Phone Model and Update.    |\n"
	   "|10.Reverse list.                        |\n"
	   "|11.SaveToFile.                          |\n"
	   "|12.Quit(Free)                           |\n");
    printf("Enter your choice :v__");
    scanf("%d", &m);
    switch(m){
    case 1 :{
      if(n == 0){
	so1(input1);
	n++;
      }
      else{
	rewind(input1);
	ClearData();
	so1(input1);
      }
      break;
    }
    case 2 :{
      Traversingfromroot(root);
      break;
    }
    case 3 :{
      ManualInsertion();
      break;
    }
    case 4 :{
      printf("Enter the position u wanna Insert ___");
      scanf("%d",&x);
      p=input_phone();
      InsertExpectedLocation(x,root,p);
      break;
    }
    case 5 :{
      printf("Enter the position u wanna Delete ___");
      scanf("%d",&x);
      DeleteExpectedLocation(root,x);
      break;
    }
    case 6 :{
      delFirstElement();
      break;
    }
    case 7 :{
      delCurrentElement();
      break;
    }
    case 8 :{
      FindTail(tail);
      deleteTail();
      break;
    }
    case 9 :{
      search();
      break;
    }
    case 10 :{
      root=reverse(root);
      break;
    }
    case 11 :{
      exporttodat();
      break;
    }
    case 12 :{
      printf("Goodbye !");
      ClearData();
      break;
    }
      
    }
  }
  fclose(input1);
}

