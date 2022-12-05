#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGTH 200

int main(){
  long start, end;//Start and end line
  int i; //mark the lines
  FILE *fptr_in, *fptr_out, *read;
  char* str;
  str = (char*)malloc(MAX_LENGTH*sizeof(char));
  if(str == NULL){
    printf("Memory allocation failed!");
    return 1;
  }
  
  fptr_in = fopen("Dictionary.txt", "r");
  if(fptr_in == NULL){
    printf("Cannot open %s!", "Dictionary.txt");
    return 1;
  }

  fptr_out = fopen("Dictionary_bin.dat", "wb");
  if(fptr_out == NULL){
    printf("Cannot open %s!", "Dictionary_bin.dat");
    return 1;
  }

  while((fgets(str, MAX_LENGTH, fptr_in)) != NULL){
    fwrite(str, MAX_LENGTH*sizeof(char), 1, fptr_out);
  }
  fclose(fptr_in);
  fclose(fptr_out);
  
  read = fopen("Dictionary_bin.dat", "rb");
  if(read == NULL){
    printf("Cannot open %s.", "Dictionary_bin.dat");
    return 1;
  }
    
  /*---Input the starting and ending line that you want to print out---*/
  printf("Input the starting line: ");
  scanf("%ld", &start);
  while(start < 0){
    printf("Invalid number! Input again: ");
    scanf("%ld", &start);
  }
  printf("Input the ending line: ");
  scanf("%ld", &end);
  while(end < start || end > 54377){
    printf("Ending number must be > starting number! Input again: ");
    scanf("%ld", &end);
  }

  /*---Bring the pointer to the starting point---*/
  fseek(read, start*MAX_LENGTH*sizeof(char), SEEK_SET);
  for(i = start; i <= end; i++){
    fread(str, MAX_LENGTH*sizeof(char), 1, read);
    printf("%s \n", str);
  }
  
  free(str);
  fclose(read);
}

