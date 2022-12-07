#include "stackstruct.h"
#include <stdlib.h>
#include<stdio_ext.h>

int main(){
  Stack *s1,*s2;
  char choice;
  int check = 0;
  int n,m;

  s1 = (Stack*)calloc(1,sizeof(Stack));
  if(s1 == NULL)
    {
      printf("Can't allocate memory for stack!\n");
      return 1;
    }
  
  s2 = (Stack*)calloc(1,sizeof(Stack));
  if(s2 == NULL)
    {
      printf("Can't allocate memory for stack!\n");
      return 1;
    }
  
  initialize(s1);
  initialize(s2);

  while(1){
    printf("      \n____MENU____\n");
    printf("|1.Add 1 interger to stack |\n");
    printf("|2.View top                |\n");
    printf("|3.Remove from the stack   |\n");
    printf("|4.Undo                    |\n");
    printf("|5.Exit                    |\n");
    printf("____________\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c",&choice);
    
    switch(choice){
    case '1':{
      printf("Input interger u want add to stack:");
      scanf("%d",&n);
      push(n,s1);
      push(0,s2);
      printf("Successful!\n");
      check = 1;
      break;
    }
    case '2':{
      if(check == 0){
	printf("Stack is empty!\nPress 1 to push element to stack\n");
	break;
      }
      else
	{
	  printf("Element in top is:%d\n",peek(*s1));
	  break;
	}
    }
    case '3':{
      if(isEmpty(*s1)){
	printf("Stack is empty!\n");
	break;
      }
      if(check == 0){
	printf("Stack is empty!\nPress 1 to push element to stack\n");
	break;
      }
      else{
	n = pop(s1);
	push(n,s2);
	push(1,s2);
	break;
      }
      
      if(isEmpty(*s1)){
	check = 0;
      }
    }
      /*
	Thuat toan Undo :
	* Dat add la 1, remove la 0
	+ Neu la add -> undo la remove -> push vao stack2 gia tri 0 de khi undo lay gia tri 0 ra thi biet la can lam nguoc lai 
	+ Neu la remove -> push vao stack2 gia tri 1 va so vua remove de khi undo lay gia tri 1 biet la can push lai vao gia tri vua pop ra
	+ Khi undo cung can push nguoc lai vao s2 de khi undo cua undo con dung
      */
    case '4':{
      m = pop(s2);
      
      if(m == 0){//Remove -> push 1 vao s2 de sau nay undo = add
	n=pop(s1);
	push(n,s2);
	push(1,s2);
	printf("Successful!\n");
      }
      else if(m == 1){//Add -> push 0 vao s2 de sau nay undo = remove
	n = pop(s2);
	push(n,s1);
	push(0,s2);
	printf("Successful!\n");
      }
      
      break;
    }
    
    case '5':{
      printf("Bye\n");
      return 0;
      break;
    }
      
    default:
      printf("Invalid syntax!\n");
      break;
    }     
  }

  return 0;
}
