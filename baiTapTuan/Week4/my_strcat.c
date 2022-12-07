/* Chuong trinh thay the ham strcat trong thu vien <string.h> */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CONSTANT 100

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Wrong Syntax! Should be: my_strcat <string1> <string2>\n");
    return 1;
  }
  else{
    int length1, length2;
    char* result;
    length1 = strlen(argv[1]);
    length2 = strlen(argv[2]);

    result = (char*)malloc((length1 + length2 + 1)*sizeof(char));

    if(result == NULL){
      printf("Allocation failed!");
      return 1;
    }

    strcpy(result, argv[1]);
    strcpy(result + length1, argv[2]);
    
    printf("String after: %s\n", result);
    
    free(result);
  }
  return 0;
}
