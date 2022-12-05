#include<stdio.h>
#define CONSTANT 100

int main(int argc, char* argv[]){
  char str[CONSTANT];
  int line;
  if(argc != 2){
    printf("Wrong Syntax! Should be: cat <file_name>");
    return 1;
  }
  else{
    FILE* fptr = fopen(argv[1], "r");

    if(fptr == NULL){
      printf("Cannot open %s.", argv[1]);
      return 1;
    }
    else{
      printf("Reading file %s... done!\n", argv[1]);
      while(fgets(str, CONSTANT, fptr) != NULL){
	printf("%s", str);
	line++;
      }
      printf("This file has %d lines.", line);
      fclose(fptr);
    }
  }
  return 0;
}
