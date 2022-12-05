#include<stdio.h>
#include<stdlib.h>

#define ID_LENGTH 20
#define NAME_LENGTH 50

typedef struct Student_t{
  char id[ID_LENGTH];
  char name[NAME_LENGTH];
  int grade;
}student;

typedef struct node_el{
  student stu;
  struct node_el *next;
}node;

node *root, *cur, *prev;

student *add_student(student *root, student *to_add){
  student *cur_std, *prev_std == NULL;
  if(root == NULL){
    return to_add;
  }
  if(to_add->grade > root->grade){
    to_add->next = root;
    return to_add;
  }

  cur_std = root;
  while(cur_std != NULL && to_add->grade < cur_std->grade){
    prev_std = cur_std;
    cur_std = cur_std->next;
  }

  prev_std->next = to_add;
  to_add->next = cur_std;

  return root;
}

int main(){
  
  
}
