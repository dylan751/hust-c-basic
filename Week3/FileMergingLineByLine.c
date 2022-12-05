/*---Chuong trinh tron xen ke tung dong cua file1 va file2 voi nhau---*/

#include<stdio.h>
#define CONSTANT 100

int main(int argc, char* argv[]){
  char str1[CONSTANT];
  char str2[CONSTANT];

  if(argc != 4){
    printf("Wrong Syntax! Should be: merge <file1> <file2> <file3>");
    return 1;
  }
  else{
    FILE* fptr1 = fopen(argv[1], "r");
    FILE* fptr2 = fopen(argv[2], "r");
    FILE* fptr3 = fopen(argv[3], "w");
    
    if(fptr1 == NULL){
      printf("Cannot open %s.", argv[1]);
      return 1;
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.", argv[2]);
      return 1;
    }
    else if(fptr3 == NULL){
      printf("Cannot open %s.", argv[3]);
      return 1;
    }
    else{
      while(fgets(str1, CONSTANT, fptr1) != NULL && fgets(str2, CONSTANT, fptr2) != NULL){
        fputs(str1, fptr3);
	fputs(str2, fptr3);
      }

      while(fgets(str1, CONSTANT, fptr1) != NULL){
	fputs(str1, fptr3);
      }
      while(fgets(str2, CONSTANT, fptr2) != NULL){
	fputs(str2, fptr3);
      }
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
  }
}
