#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void so1(FILE*input,char*k){ // copy file theo tung ki tu
  FILE*output=fopen("HW3_in.txt","w");
  int c;
  while((c=fgetc(input))!=EOF){
    putchar(c);
    fputc(c,output);
  }
          
  fclose(output);
}
void so2(FILE*input,char*k){ // copy file theo tung dong
  FILE*output=fopen("HW3_in.txt","w");
  while(fgets(k,201,input)!=NULL){
    puts(k);
    fputs(k,output);
  }
  fclose(output);
}
void so3(FILE*input,char*k,int a){ // copy file theo khoi, kich co tuy chon
  int num;
  FILE*output=fopen("HW3_in.txt","wb");
  while(!feof(input)){
    num=fread(k,sizeof(char),100,input);
      
    fwrite(k,sizeof(char),num,output);
  }
  fclose(output);
}
int main(int argc, char*argv[]){
  int b,a;
  clock_t x,y; // khai bao bien kieu thoi gian
  char *k;
  
  if(argc!=2){
    printf("Wrong Syntax! Should be: HW3 <file_name>");
    return 0;
  }
  
  k = (char*)malloc(200*sizeof(char));
  if(k == NULL){
    printf("Memory allocation failed !");
    return 0;
  }
  FILE*input;
  input = fopen(argv[1],"r");
  if(input == NULL){
    printf("Cannot open %s", argv[1]);
    return 0;
  }
  
  while(b!=4){
    printf("|           === Menu===           |\n"
	   "|1. Copy by characters            |\n"
	   "|2. Copy by line                  |\n"
	   "|3. Copy by block - optional size |\n"
	   "|4. Exit                          |\n");
    scanf("%d",&b);
    fseek(input,0,SEEK_SET);// ham nay dung de lui con tro lai ve vi tri ban dau, co gi mai t noi cai nay
    switch(b){
    case 1 :{
      x=clock();// thoi gian truoc khi thuc hien ham
      so1(input,k);
      y=clock();// thoi gian sau khi thuc hien ham
      printf("The process takes %lf s to finish !\n",(double)(y-x)/CLOCKS_PER_SEC);// thoi gian de hoan thanh chuc nang da chon
      
      break;
    }
    case 2 :{
      x=clock();
      so2(input,k);
      y=clock();
      printf("The process takes %lf s to finish !\n",(double)(y-x)/CLOCKS_PER_SEC);
      break;
    }
    case 3 :{
      printf("Enter numbers data u wanna read at one moment :__");
      scanf("%d",&a);
      x=clock();
      so3(input,k,a);
      y=clock();
      printf("\nThe process takes %lf s to finish !\n",(double)(y-x)/CLOCKS_PER_SEC);
      break;
    }
    }
  }
  free(k);
  fclose(input);
}
