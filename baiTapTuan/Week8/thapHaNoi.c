#include<stdio.h>

void towers(int num, char frompeg, char topeg, char auxpeg){
  if(num == 1){
    printf("\nDisk 1: %c -> %c", frompeg, topeg);
    return;
  }
  towers(num - 1, frompeg, auxpeg, topeg);
  printf("\nDisk %d: %c -> %c", num, frompeg, topeg);
  towers(num - 1, auxpeg, topeg, frompeg);
}

int main(){
  int num;
  printf("Enter the number of disks: ");
  scanf("%d", &num);
  printf("The sequence of moves involved in the Tower of Hanoi are: \n");
  towers(num, 'A', 'B', 'C');
  return 0;
}
