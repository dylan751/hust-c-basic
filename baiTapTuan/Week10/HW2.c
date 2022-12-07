#include <stdio.h>
#include "queueList.h"

void CreatNewProgram(Queue *q1,Queue *q2,int *memory,int *count,int nop);
void KillProcess(Queue *q1,Queue *q2,int *memory,int *count,int nop);
void ShowProcess(Queue *q1,Queue *q2);


int main()
{
  int memory;
  int dongThoi;//So chuong trinh chay dong thoi
  int choice;
  int count=0;
  Queue *q1,*q2;
  Node u;

  q1 = (Queue*)calloc(1,sizeof(Queue));
  if(q1 == NULL)
    {
      printf("Can't allocate memory for queue!\n");
      return 1;
    }

  q2 = (Queue*)calloc(1,sizeof(Queue));
  if(q2 == NULL)
    {
      printf("Can't allocate memory for queue!\n");
      return 1;
    }
  
  MakeNullQueue(q1);
  MakeNullQueue(q2);

  printf("Input parallel process it can run:");
  do
    {
      scanf("%d",&dongThoi);
    }
  while(dongThoi <= 0);
  
  printf("Input memory capacity:");
  do
    {
      scanf("%d",&memory);
    }
  while(memory <=0);


  while(1)
    {
      printf("\n______PROCESS MENU_______\n");
      printf("1.Create new program\n");
      printf("2.Kill a program\n");
      printf("3.Show the status of running and waitting processes\n");
      printf("4.Exit\n");
      printf("Your choice:");
      scanf("%d",&choice);

      switch(choice)
	{
	case 1:
	  CreatNewProgram(q1,q2,&memory,&count,dongThoi);
	  printf("Sucessful!\n");
	  break;

	case 2:
	  KillProcess(q1,q2,&memory,&count,dongThoi);
	  printf("Sucessful!\n");
	  break;

	case 3:
	  ShowProcess(q1,q2);
	  break;

	case 4:
	  printf("Bye!\n");
	  return 0;
	  break;

	default:
	  printf("Invalid syntax!\n");
	  break;
	}
    }
  
  
  return 0;
}

void CreatNewProgram(Queue *q1,Queue *q2,int *memory,int *count,int dongThoi)
{
  ElementType x;

  printf("Input the memory size of program:");
  scanf("%d",&x.memory);
  printf("Input the program ID:");
  scanf("%d",&x.id);
  
  if(x.memory <= *memory)
    {
      if(*count < dongThoi)
	{
	  *count = *count + 1;
	  x.status = 1;
	  *memory = *memory - x.memory;
	  EnQueue(q1,x);
	}
      else
	{
	  x.status = 0;
	  EnQueue(q2,x);
	}
    }
  else
    {
      x.status = 0;
      EnQueue(q2,x);
    }
  
  return;
}

void KillProcess(Queue *q1,Queue *q2,int *memory,int *count,int dongThoi)
{
  Node m = DeQueue(q1);
  *count = *count - 1;
  *memory = *memory + m.Element.memory;
  printf("%d\n",*count);
  
  while(1)
    {
      if(isEmptyQueue(*q2))
	{
	  break;
	}

      if(q2->Front->Element.memory <= *memory)
	{
	  if(*count >= dongThoi)
	    {
	      break;
	    }
	  else
	    {
	      *memory = *memory - q2->Front->Element.memory;
	      m = DeQueue(q2);
	      //printf("%d\n",m.Element.memory);
	      EnQueue(q1,m.Element);
	      *count = *count +1;
	    }
	}
      else
	{
	  break;
	}
    }
  
  return;
}

void ShowProcess(Queue *q1,Queue *q2)
{
  Node p;
  Queue *q3,*q4;

  q3 = (Queue*)calloc(1,sizeof(Queue));
  if(q3 == NULL)
    {
      printf("Can't allocate memory for queue!\n");
      return;
    }

  q4 = (Queue*)calloc(1,sizeof(Queue));
  if(q4 == NULL)
    {
      printf("Can't allocate memory for queue!\n");
      return;
    }
  
  MakeNullQueue(q3);
  MakeNullQueue(q4);

  
  printf("%5s %10s %10s\n","ID","Memory","Queue");

  while(1)
    {
      if(isEmptyQueue(*q1) && isEmptyQueue(*q2))
	{
	  break;
	}
      
      if(isEmptyQueue(*q2))
	{
	  p = DeQueue(q1);
	  printf("%5d %10d\n",p.Element.id,p.Element.memory);
	  EnQueue(q3,p.Element);
	}
      else if(isEmptyQueue(*q1))
	{
	  p = DeQueue(q2);
	  printf("%5d %20d\n",p.Element.id,p.Element.memory);
	  EnQueue(q4,p.Element);
	}
      else if(q1->Front->Element.id < q2->Front->Element.id)
	{
	  p = DeQueue(q1);
	  printf("%5d %10d\n",p.Element.id,p.Element.memory);
	  EnQueue(q3,p.Element);
	}
      else
	{
	  p = DeQueue(q2);
	  printf("%5d %20d\n",p.Element.id,p.Element.memory);
	  EnQueue(q4,p.Element);
	}
    }

  while(1)
    {
      if(isEmptyQueue(*q3) && isEmptyQueue(*q4))
	{
	  break;
	}

      while(!isEmptyQueue(*q3))
	{
	  p = DeQueue(q3);
	  EnQueue(q1,p.Element);
	}

      while(!isEmptyQueue(*q4))
	{
	  p = DeQueue(q4);
	  EnQueue(q2,p.Element);
	}
    }

  return;
}
