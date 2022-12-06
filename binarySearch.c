#include<stdio.h>
#define NotFound -1

typedef int elementtype;

int BinarySearch(elementtype A[], elementtype X, int N){
  int low, mid, high;
  low = 0, high = N-1;
  while(low <= high){
    mid = (low+high)/2;
    if(A[mid] < X){
      low = mid + 1;
    }
    else if(A[mid] > X){
      high = mid - 1;
    }
    else return mid;
  }
  return NotFound;
}

int main(){
  static int A[] = {1, 3, 5, 6, 9, 13, 15};
  int SizeofA = sizeof(A) / sizeof(A[0]);
  int i;

  for(i = 0; i < 20; i++){
    printf("BinarySearch of %d returns %d\n", i, BinarySearch(A, i, SizeofA));
  }
  return 0;
}
