#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define CONSTANT 100

typedef struct{
 char name[CONSTANT];
 char tel[CONSTANT];
 char email[CONSTANT];
}phone;

int main(int argc, char*argv[]){
  int line_num;
  long b;
  FILE*input, *output1, *output2;
  phone*p;
  if(argc != 5){
    printf("Error! The correct syntax is ./filesplit <chosen file> <number> <file_1> <file_2>!");
    return 1;
  }
  line_num = atoi(argv[2]);
  while(line_num < 0){
    printf("Error ! Enter the ending point of file %s u want : ___",argv[1]);
    scanf("%d ",&line_num);
  }

  p=(phone*)malloc(line_num*sizeof(phone));
  
  input=fopen(argv[1],"rb");
  if(input == NULL){
    printf("No such file or directory !__");
    return 0;
  }
  output1=fopen(argv[3], "wb");
  if(output1 == NULL){
    printf("No such file or directory !__");
    return 0;
  }
  output2=fopen(argv[4], "wb");
  if(output2 == NULL){
    printf("No such file or directory !__");
    return 0;
  }

  fread(p, sizeof(phone), line_num, input);
  fwrite(p, sizeof(phone), line_num, output1);
    
  while((int*)fread(p, sizeof(phone), 1, input) != NULL){
    fwrite(p,sizeof(phone), 1, output2);
  }
  
  fclose(input);
  fclose(output1);
  fclose(output2);
  free(p);
 }

