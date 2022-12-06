#include<stdio.h>

int print(int a, int n){
  if(a <= n){
    printf("%d ", a);
    print(a+1, n);
  }
}

int main(){
  int n;
  printf("Nhap n: ");
  scanf("%d", &n);
  if(n <= 0){
    printf("Nhap n>0! Nhap lai: ");
  }
  print(1, n);
}
