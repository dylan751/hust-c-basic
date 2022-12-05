#include<stdio.h>
#include<string.h>

#define CONSTANT 50

int main(int argc, char *argv[]){
  char c;
  if(argc != 3){
    printf("Wrong Syntax! Should be: mycp <FILE_NAME> <FILE_NAME>");
    return 1;
  }
  else{
    FILE *fptr1 = fopen(argv[1], "r");
    FILE *fptr2 = fopen(argv[2], "w");

    if(fptr1 == NULL){
      printf("Cannot open %s.\n", argv[1]);
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.\n", argv[2]);
    }
    
    while((c = fgetc(fptr1)) != EOF){
      fputc(c, fptr2);
      putchar(c);
    }
    fclose(fptr1);
    fclose(fptr2);
  }
}
