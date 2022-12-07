#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef char* elementType;

void insertionSort(elementType *str, int n){
  int i, j;
  elementType next;
  for(i = 1; i < n; i++){
    next = arr[i];
    for(j = i-1; j >= 0 && next < arr[j]; j--){
      arr[j+1] = arr[j];
    }
    arr[j+1] = next;
  }

  for(i = 0; i < n; i++){
    printf("%5d", arr[i]);
  }
  printf("\n");
}

int main(){
  clock_t t1, t2;
  srand(time(NULL));
  elementType str[10];
  int i;
  FILE* fptr = fopen("ten.txt", "r");
  if(fptr == NULL)
    return -1;

  
  insertionSort(str, 10);

  return 0;
}
