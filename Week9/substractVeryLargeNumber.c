#include<stdio.h>
#include<string.h>
#include"stackarr(DungMangCauTruc).h"
//MAX = 100

/*Return 1-> num1>num2,    return 0-> num1=num2     return -1-> num1<num2*/
int compare(char *num1, char *num2){
  int i;
  
  if(strlen(num1) > strlen(num2)){
    return 1;
  }
  else if(strlen(num1) < strlen(num2)){
    return -1;
  }
  else{
    for(i = 0; i < strlen(num1); i++){
      if(num1[i] > num2[i]){
	return 1;
      }
      else if(num1[i] < num2[i]){
	return -1;
      }
      else{
	continue;
      }
    }

    return 0;//Neu khong thoa man nhung DK tren -> num1 = num2
  }
  
}

/*---Algorithm for s1 > s2---*/
void subtract(StackType s1, StackType s2, StackType result){
  int c1, c2, res;
  c1 = c2 = res = 0;
  int i, soDu = 0;
  
  while(!isEmpty(s1) || !isEmpty(s2)){
    if(!isEmpty(s1)){
      c1 = pop(&s1);
    }
    else c1 = 0;

    if(!isEmpty(s2)){
      c2 = pop(&s2);
    }
    else c2 = 0;

    if(c1 - c2 - soDu >= 0){
      res = c1 - c2 - soDu;
      push(res, &result);
      soDu = 0;
    }
    else{
      res = c1 + 10 - c2 - soDu;
      soDu = 1;
      push(res, &result);
    }
  }

  while(!isEmpty(result)){
    printf("%d", pop(&result));
  }
}

int main(){
  StackType s1, s2, result;
  int i;
  char num1[MAX];
  char num2[MAX];

  initialize(&s1);
  initialize(&s2);
  initialize(&result);

  printf("---This program can subtract very large number!---\n");

  printf("Input the first number: ");
  scanf("%s", num1);

  printf("Input the second number: ");
  scanf("%s", num2);

  for(i = 0; i < strlen(num1); i++){
    push(num1[i] - '0', &s1);
  }
  for(i = 0; i < strlen(num2); i++){
    push(num2[i] - '0', &s2);
  }

  if(compare(num1, num2) == 0){//Neu num1 = num2
    printf("Subtract = 0");
  }
  else if(compare(num1, num2) > 0){//Neu num1 > num2
    printf("Subtract = ");
    subtract(s1, s2, result);
  }

  else{//Neu num1 < num2
    printf("Subtract = ");
    printf("-");//Dau tru
    subtract(s2, s1, result);//Lay s2 - s1 vi s2 > s1
  }
}
