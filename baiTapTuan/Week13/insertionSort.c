#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef int elementType;

void insertionSort(elementType arr[], int n){
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
  elementType arr[10001];
  int i;
  
  for(i = 0; i < 10000; i++){
    arr[i] = rand()%10000;
  }

  t1 = clock();
  insertionSort(arr, 10000);
  t2 = clock();
  printf("\nThoi gian = %lf\n", (double)(t2 - t1)/CLOCKS_PER_SEC);
  return 0;
}
