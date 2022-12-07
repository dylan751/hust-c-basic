/*---Copy from a file into a file and add line number at the beginning of each line---*/

#include<stdio.h>
#define CONSTANT 100

int main(int argc, char* argv[]){
  char str[CONSTANT];
  int line = 1;
  if(argc != 3){
    printf("Wrong Syntax! Should be: mycp <file_name> <file_name>");
    return 1;
  }
  else{
    FILE* fptr1 = fopen(argv[1], "r");
    FILE* fptr2 = fopen(argv[2], "w");

    if(fptr1 == NULL){
      printf("Cannot open %s.", argv[1]);
      return 1;
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.", argv[2]);
      return 1 ;
    }
    while(fgets(str, CONSTANT, fptr1) != NULL){
      fprintf(fptr2, "%d. ", line); 
      fputs(str, fptr2);
      line++;
    }
    
    fclose(fptr1);
    fclose(fptr2);
  }
  return 0;
}
