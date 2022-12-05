#include<stdio.h>
int main(){
  int c;
  char name1[10]="lab1.txt";
  char name2[10]="lab1w.txt";
  FILE *fprt_input = fopen(name1,"r");
  FILE *fprt_output = fopen(name2,"w");
  if(fprt_input==NULL){
    printf("Cannot open %s.\n",name1);
    return 1;
  }
  else if(fprt_output==NULL){
    printf("Cannot open %s.\n",name2);
    return 1;
  }
  else 
    while((c=fgetc(fprt_input))!=EOF){
      if(c>='a'&&c<='z')c+='A'-'a';
      else if(c>='A'&&c<='Z')c+='a'-'A';
      fputc(c,fprt_output);
      putchar(c);
    }
  fclose(fprt_input);
  fclose(fprt_output);
  return 0;
}
