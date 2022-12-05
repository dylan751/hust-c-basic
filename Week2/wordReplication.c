#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CONSTANT 10

int main(int argc, char *argv[]){
  int i;
  char word[CONSTANT];
  int reps; //so lan lap

  if(argc != 3){
    printf("Wrong! Should be <word><times>");
    return 1;
  }

  reps = atoi(argv[2]);

  for(i = 0; i < reps; i++){
    printf("%s", argv[1]);
  }
}
