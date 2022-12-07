
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define CONSTANT 100

typedef struct phoneaddress{
  char model[CONSTANT];
  char memory_space[CONSTANT];
  double screen_size;
  double price;
}phone;


void read(FILE*fp, phone*p){
  int i = 0;
  while((int*)fread(p, sizeof(phone), 1, fp) != NULL){
    printf("%2d %20s %10s %10.2lf %10.2lf\n",i+1,p->model,p->memory_space,p->screen_size, p->price);
    i++;
  }
}

int main(int argc, char*argv[]){
  if(argc != 2){
    printf("Error! The correct syntax is ./readfile <chosen file>!");
    return 1;
  }
  FILE *fp = fopen(argv[1],"rb");
  phone *p;
  int i, n, irc;
  if(fp == NULL){
    printf("Cannot open %s !\n",argv[1]);
    return 1;
  }
  p=(phone*)malloc(1*sizeof(phone));
  if(p == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  read(fp,p);
  fclose(fp);
  free(p);
  return 0;
}
