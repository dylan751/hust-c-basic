#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef int element;

void adjust(element list[], int root, int n){
  int child, rootkey;
  element temp;
  temp = list[root];
  rootkey = list[root];
  child = 2*root;

  while(child <= n){
    if((child < n) && (list[child] < list[child+1])){
      child++;
    }
    if(rootkey > list[child])
      break;
    else{
      list[child/2] = list[child];
      child *= 2;
    }
  }  
  list[child/2] = temp;
}


//Dang bieu dien cay bang` mang?
void heapsort(element list[], int n){
  int i, j;
  element temp;
  for(i = n/2; i > 0; i--){
    adjust(list, i, n);//Ham vun dong
  }
  for(i = n-1; i > 0; i--){
    temp = list[1];
    list[1] = list[i+1];
    list[i+1] = temp;

    adjust(list, 1, i);//Ham vun dong
  }

  for(i = 0; i < n; i++){
    printf("%5d", list[i]);
  }
}

int main(){
  clock_t t1, t2;
  srand(time(NULL));
  
  element arr[10001];
  int i;
  
  for(i = 1; i <= 10000; i++){
    arr[i] = rand()%10000;
  }

  t1 = clock();
  //Chi sap xep tu phan tu thu arr[1] tro di (phan tu arr[0] khong tinh)
  heapsort(arr, 10000);
  t2 = clock();

  printf("\nThoi gian = %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);
}
