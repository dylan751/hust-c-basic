#include<stdio.h>

int main(){
  char file_name[50] = "class1EF.txt";
  FILE* fptr1 = fopen(file_name, "r+");
  FILE* fptr2 = fopen("output.txt", "w");
  if(fptr1 == NULL){
    printf("Cannot open %s", file_name);
    return 1;
  }
  else if(fptr2 == NULL){
    printf("Cannot open %s", "output.txt");
    return 1;
  }
  else{
    char c;
    while((c = fgetc(fptr1)) != EOF){
      fputc(c, fptr2);
      if(c == '\n'){
	fputc(c, fptr2);
      }
    }

    fclose(fptr1);
    fclose(fptr2);
  }
}
