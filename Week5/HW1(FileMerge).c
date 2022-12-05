#include<stdio.h>
#include<stdlib.h>

#define CONSTANT 100

typedef struct{
 char name[CONSTANT];
 char tel[CONSTANT];
 char email[CONSTANT];
}phone;

int main(int argc, char* argv[]){
  phone* phonearr;
  phonearr = (phone*)malloc(1*sizeof(phone));
  
  if(argc != 4){
    printf("Wrong Syntax! Should be: filemerge <file1> <file2> <file_merge>");
    return 1;
  }

  FILE *fptr1, *fptr2, *fptr_out;
  fptr1 = fopen(argv[1], "rb");
  if(fptr1 == NULL){
    printf("Cannot open %s.", argv[1]);
    return 1;
  }
  
  fptr2 = fopen(argv[2], "rb");
  if(fptr2 == NULL){
    printf("Cannot open %s.", argv[2]);
    return 1;
  }

  fptr_out = fopen(argv[3], "wb");
  if(fptr_out == NULL){
    printf("Cannot open %s.", argv[3]);
    return 1;
  }

  while((int*)fread(phonearr, sizeof(phone), 1, fptr1) != NULL){
    fwrite(phonearr, sizeof(phone), 1, fptr_out);
  }

  while((int*)fread(phonearr, sizeof(phone), 1, fptr2) != NULL){
    fwrite(phonearr, sizeof(phone), 1, fptr_out);
  }
  
  free(phonearr);
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr_out);
}
