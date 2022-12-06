#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stackarr(DungMangCauTruc).h"

int main(){
  int i = 0, soDu = 0;
  char num1[MAX];
  char num2[MAX];
  int c1, c2, res;
  c1 = c2 = res = 0;
  
  StackType s1, s2, result;
  initialize(&s1);
  initialize(&s2);
  initialize(&result);

  printf("---This program can add very large number!---\n");
  
  printf("Input the first number: ");
  scanf("%s", num1);
  printf("Input the second number: ");
  scanf("%s", num2);

  for(i = 0; i < strlen(num1); i++){
    push(num1[i] - '0'/*Chuyen ve kieu int*/, &s1);
  }
  
  for(i = 0; i < strlen(num2); i++){
    push(num2[i] - '0', &s2);
  }
  
  while(!isEmpty(s1) || !isEmpty(s2)){
    if(!isEmpty(s1)){//Neu stack 1 ko rong
      c1 = pop(&s1);
    }
    else{
      c1 = 0;
    }
    
    if(!isEmpty(s2)){
      c2 = pop(&s2);
    }
    
    else c2 = 0;
    
    if(c1 + c2 + soDu >= 10){
      res = c1 + c2 + soDu - 10;
      push(res, &result);
      soDu = (c1+c2+soDu)/10;
    }
    else{
      res = c1 + c2 + soDu;
      push(res, &result);
      soDu = 0;
    }
  }
  
  if(soDu > 0) push(soDu, &result);
  printf("The sum = ");
  while(!isEmpty(result)){
    printf("%1d", pop(&result));
  }
  printf("\n");
  return 0;
}
