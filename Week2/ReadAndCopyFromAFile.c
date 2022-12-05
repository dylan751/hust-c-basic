#include<stdio.h>
#include<stdio_ext.h>
#define CONSTANT 10

int main(){
  int c;
  char name1[CONSTANT] = "lab1.txt";
  char name2[CONSTANT] = "lab1w.txt";
  FILE *fptr_input = fopen(name1, "r");
  FILE *fptr_output = fopen(name2, "w");
  if(fptr_input == NULL){
    printf("Cannot open %s.", name1);
    return 1;
  }
  else if(fptr_output == NULL){
    printf("Cannot open %s.", name2);
    return 1;
  }
  else{
    while(c = fgetc(fptr_input) != EOF){
      fputc(c, fptr_output); /*write to a file*/
      putchar(c);
    }

    fclose(fptr_input);
    fclose(fptr_output);   
  }
}
