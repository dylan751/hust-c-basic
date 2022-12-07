#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 80

int main(int argc, char *argv[]){
  char c;
  if(argc != 3){
    printf("Wrong Syntax! Should be: mycp <FILE_NAME> <FILE_NAME>");
    return 1;
  }
  else{
    FILE *fptr1 = fopen(argv[1], "r");
    FILE *fptr2 = fopen(argv[2], "w");
    char buff[MAX_LEN+1];
    int num;
    
    if(fptr1 == NULL){
      printf("Cannot open %s.\n", argv[1]);
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.\n", argv[2]);
    }
    
    while(!feof(fptr1)){
      num = fread(buff, sizeof(char), MAX_LEN, fptr1);
      buff[num] = '\0';

      printf("%s", buff);
      
      fwrite(buff, sizeof(char), num, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
  }
}
