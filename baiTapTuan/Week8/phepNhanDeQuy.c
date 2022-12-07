/*---Chuong trinh nhan 2 so bang phuong phap de quy---*/
#include<stdio.h>

int power(int a, int b){
  if(b > 0)
    return a + power(a, b-1);
  else{
    return 0;
  }
}

int main(){
  int a, b;
  printf("Nhap a, b: ");
  scanf("%d%d", &a, &b);

  printf("%d x %d = %d", a, b, power(a, b));
}
