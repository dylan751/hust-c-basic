#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include"binarySearchTree.h"

#define CONSTANT 100

elementType input_phone(){
  __fpurge(stdin);
  elementType p;
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

void importFromDat(FILE* input1, treeType *root){
  elementType *p = (elementType*)malloc(sizeof(elementType));;
  elementType m;
  
  while((elementType*)fread(p, sizeof(elementType), 100, input1) != NULL){
    m = *p;
    insertNode(m, &(*root));
  }
}

void importFromText(FILE* input, treeType *root){
  elementType *p = (elementType*)malloc(sizeof(elementType));
  elementType m;
  while(fscanf(input, "%s\t%s\t%lf\t%lf", p->model, p->memory, p->size, p->price) != EOF){
    m = *p;
    printf("%30s%20s%10lf%10lf\n", m.model, m.memory, m.size, m.price);
  }
}

int main(){
  FILE *input1, *input2, *output;
  treeType root = (nodeType*)malloc(sizeof(nodeType));
  
  input1 = fopen("PhoneDB.dat","rb");
  if(input1 == NULL){
    printf("No such file or directory!\n");
    return 0;
  }
  input2 = fopen("PhoneDB.txt", "r");
  if(input2 == NULL){
    printf("No suck file or directory!\n");
    return 0;
  }
  
  int n1, n2;//dung cho menu 10
  int i;
  int x;
  int choice, n = 0;
  elementType p;

  makeNullTree(&root);
  
  while(choice != 9){
    printf("               ---Menu---\n"
	   "|1. Import Database from .dat file.    |\n"
	   "|2. Import Database from .text file.   |\n"
	   "|3. Add phone model.                   |\n"
	   "|4. Delete.                            |\n"
	   "|5. Update.                            |\n"
	   "|6. Searching.                         |\n"
	   "|7. Displaying.                        |\n"
	   "|8. Save data.                         |\n"
	   "|9. Exit.                              |\n");
    printf("Enter your choice :v__");
    scanf("%d", &choice);
    switch(choice){
    case 1 :{
      if(n == 0){//Neu la lan dau nhap
	importFromDat(input1, &root);
	n++;
      }
      else{
	rewind(input1);
	freeTree(root);
	importFromDat(input1, &root);
      }
      break;
    }
      case 2 :{
	importFromText(input2, &root);
	break;
      }
    /*case 3 :{
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
      }*/
    case 7 :{
      inOrderPrint(root);
      break;
    }
    /*
    case 8 :{
      FindTail(tail);
      deleteTail();
      break;
    }
    case 9 :{
      search();
      break;
    }
   
      */
    }
    }
  fclose(input2);
  fclose(input1);
}
