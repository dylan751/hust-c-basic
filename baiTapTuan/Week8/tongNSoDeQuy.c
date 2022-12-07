#include<stdio.h>

int calculate(int n){
  if(n == 0){
    return 0;
  }
  else{
    return n + calculate(n-1);
  }
}

int main(){
  int n;
  printf("Input a number: ");
  scanf("%d", &n);
  while(n < 0){
    printf("N must be >0! Input again: ");
    scanf("%d", &n);
  }
  printf("The sum of numbers from 1 to %d = %d\n", n, calculate(n));
}
