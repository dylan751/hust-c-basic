#include"stackarr(DungMangCauTruc).h"
#include<string.h>

int main(){
  char *num1, *num2, *num3;
  num1 = (char*)malloc(sizeof(char));
  num2 = (char*)malloc(sizeof(char));
  num3 = (char*)malloc(sizeof(char));
  StackType s1, s2, s3;
  int i;
  int a, b, soDu = 0, result;

  printf("---This program can add very large number!---\n");
  
  printf("Input the first number: ");
  scanf("%s", num1);

  printf("Input the second number: ");
  scanf("%s", num2);

  initialize(&s1);
  initialize(&s2);
  initialize(&s3);
  
  //Dua cac chu so lan luot vao stack 1, stack 2
  for(i = 0; i < strlen(num1); i++){
    push(num1[i] - '0', &s1);
  }
  for(i = 0; i < strlen(num2); i++){
    push(num2[i] - '0', &s2);
  }

  //Neu ca 2 stack khong rong~
  while(!isEmpty(s1) && !isEmpty(s2)){
    a = pop(&s1);
    b = pop(&s2);

    if(a+b+soDu >= 10){
      result = (a+b+soDu)%10;
      soDu = 1;
      push(result, &s3);
    }
    else{
      result = a+b+soDu;
      soDu = 0;
      push(result, &s3);
    }
  }

  //Neu stack chua rong~ -> pop het ra
  while(!isEmpty(s1)){
    a = pop(&s1);
    if(a+soDu >= 10){
      result = a+soDu;
      soDu = 1;
      push(result, &s3);
    }
    else{
      result = a+soDu;
      soDu = 0;
      push(result, &s3);
    }
  }

  //Neu stack chua rong~ -> pop het ra
  while(!isEmpty(s2)){
    b = pop(&s2);
    if(b+soDu >= 10){
      result = b+soDu;
      soDu = 1;
      push(result, &s3);
    }
    else{
      result = b+soDu;
      soDu = 0;
      push(result, &s3);
    }
  }

  if(soDu == 1){
    push(soDu, &s3);
  }

  while(!isEmpty(s3)){
    printf("%d", pop(&s3));
  }
  printf("\n");
  
  free(num1);
  free(num2);
  free(num3);
  return 0;
}
