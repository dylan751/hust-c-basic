#include<stdio.h>
#include<string.h>

#define CONSTANT 100

int main(int argc, char *argv[]){
  char str[CONSTANT];
  int i;

  if(argc != 2){
    printf("Wrong Syntax! Should be: <string>");
    return 1;
  }

  for(i = strlen(argv[1])-1; i >= 0; i--){
    printf("%c", argv[1][i]);
  }
}
