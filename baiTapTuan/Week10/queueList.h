
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int memory;
  int status;
  int id;
}ElementType;

typedef struct Node
{
  ElementType Element;
  struct Node *next;
} Node;

typedef struct 
{
  Node *Front,*Rear;
}Queue;


void MakeNullQueue(Queue *q);
int isEmptyQueue(Queue q);
Node DeQueue(Queue *q);
void EnQueue(Queue *q, ElementType x);


Node *MakeNewNode(ElementType e)
{
  Node *new_node;

  new_node = (Node*)calloc(1,sizeof(Node));
  if(new_node == NULL)
    {
      printf("Can't allocate memory!\n");
      return NULL;
    }

  new_node->Element = e;
  new_node->next = NULL;

  return new_node;
}

void MakeNullQueue(Queue *q)
{
  q->Front = NULL;
  q->Rear = NULL;
}

int isEmptyQueue(Queue q)
{
  return q.Front == NULL;
}

void EnQueue(Queue *q,ElementType e)
{
  Node *new_node = MakeNewNode(e);
  if(isEmptyQueue(*q))
    {
      q->Front = q->Rear = new_node;
    }
  else
    {
      q->Rear->next = new_node;
      q->Rear = new_node;
    }
}

Node DeQueue(Queue *q)
{
  Node x;
  Node *del;

  if(isEmptyQueue(*q))
    {
      printf("Queue is empty!\n");
    }
  else
    {
      x = *q->Front;
      del = q->Front;
      q->Front = q->Front->next;

      if(q->Front == NULL)
        {
	  q->Rear = NULL;
        }

      free(del);
    }
    
  return x;
}
