#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef int elementType;

void selectionSort(elementType arr[], int n){
  int i, j, min, tmp;
  for(i = 0; i < n-1; i++){
    min = i;
    for(j = i+1; j <= n-1; j++){
      //Find min
      if(arr[j] <= arr[min]){
	min = j;
      }
    }
    //Swap
    tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }

  for(i = 0; i < n; i++){
    printf("%5d", arr[i]);
  }
  printf("\n");
}

int main(){
  srand(time(NULL));
  elementType arr[10];
  int i;
  
  for(i = 0; i < 10; i++){
    arr[i] = rand()%10;
  }

  selectionSort(arr, 10);
  return 0;
}
