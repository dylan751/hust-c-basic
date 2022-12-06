#include<stdio.h>
#include<stdio_ext.h>
#include"binarySearchTree.h"
#include<time.h>

#define MAX 200000 //De them phan tu cuoi vao sentinel

int sequentialSearch(int arr[]){
  int key;
  int i, mark = 0;
  printf("Input the number that you want to find: ");
  scanf("%d", &key);

  for(i = 0; i < MAX; i++){
    if(arr[i] == key){
      printf("The number you want to find locates at: arr[%d]\n", i);
      mark++;
      return i;
    }
  }

  if(mark == 0){
    printf("There aren't any number fit your needs!\n");
    return -1;
  }
}

int sequentialSearchSentinel(int arr[]){
  int key, i = 0;
  printf("Input the number that you want to find: ");
  scanf("%d", &key);

  arr[MAX] = key;//Dat linh canh o cuoi mang
  while(arr[i] != key){
      i++;
  }
 
  if(i == MAX){//Neu chay toi phan tu sentinel -> khong tim thay
    printf("There aren't any number fit your needs!\n");
    return -1;
  }

  printf("The number you want to find locates at: arr[%d]\n", i);
  return i;
  
}

int binarySearch(int key, int arr[], int left, int right){
  int mid = (left + right)/2;

  if(key == arr[mid]){
    printf("The number you want to find locates at: arr[%d]\n", mid);
    return mid;
  } else if(key < arr[mid]){
    right = mid-1;
    binarySearch(key,arr, left, right);
  }
  else{
    left = mid+1;
    binarySearch(key, arr, left, right);
  }
}

int main(){
  int *arr = (int*)malloc(200001*sizeof(int));//De thua 1 o cho sentinel
  int i, key;
  int left = 0, right = MAX-1;//De cho binary search

  clock_t start, end;

  //Khai bao mang co MAX phan tu
  for(i = 0; i < MAX; i++){
    arr[i] = i+1;
  }
  
  char choice;
  while(choice != '4'){
    __fpurge(stdin);
    printf("              ---MENU---\n"
	   "|1. Sequential search.                |\n"
	   "|2. Sequential search using sentinel. |\n"
	   "|3. Binary search.                    |\n"
	   "|4. Exit.                             |\n");
    printf("Input your choice: ");
    scanf("%c", &choice);
    while(choice > '4' || choice < '1'){
      __fpurge(stdin);
      printf("Choice must be [1,4]! Input again: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1': {
      start = clock();
      sequentialSearch(arr);
      end = clock();
      printf("Execution time = %lf\n", ((double)(end-start))/CLOCKS_PER_SEC);//Ham tinh thoi gian thuc thi
      break;
    }
      
    case '2': {
      start = clock();
      sequentialSearchSentinel(arr);
      end = clock();
      printf("Execution time = %lf\n", ((double)(end-start))/CLOCKS_PER_SEC);//Ham tinh thoi gian thuc thi
      break;
    }

      
    case '3': {
      printf("Input the number that you want to find: ");
      scanf("%d", &key);
      
      start = clock();
      binarySearch(key, arr, left, right);
      end = clock();
      printf("Execution time = %lf\n", ((double)(end-start))/CLOCKS_PER_SEC);//Ham tinh thoi gian thuc thi
      break;
    }
    }
  }

  free(arr);
}
