#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//DANG LOI~

void merge(int A[], int l, int q, int r){
  int i, j, k;
  int n1 = q - l + 1;
  int n2 = r - q;
  
  int B[n1]; 
  int C[n2];

  //Tao mang tam
  for(i = 0; i < n1; i++){
    B[i] = A[l+i];
  }
  for(j = 0; j < n2; j++){
    C[j] = A[q+j+1];
  }

  //Gop 2 mang tam vua roi vao nhau
  i = 0;
  j = 0;
  k = l;
  
  while(i < n1 && j < n2){
    if(B[i] <= C[j]){
      A[k] = B[i];
      i++;
    }
    else{
      A[k] = C[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    A[k] = B[i];
    i++;
    k++;
  }
  
  //Copy cac phan tu con lai cua mang C neu co
  while(j < n2){
    A[k] = C[j];
    j++;
    k++;
  }
  
}

//l: dau, r; cuoi
void mergeSort(int *A, int l, int r){
  int q; //phan tu giua mang

  if(l < r){
    q = (l+r)/2;
    mergeSort(A, l, q);
    mergeSort(A, q+1, r);
    
    merge(A, l, q, r);
  }
}
 
int main(){
  int A[10];
  srand(time(NULL));

  int i;
  printf("Before sorted: ");
  for(i = 0; i < 10; i++){
    A[i] = rand()%10+1;
    printf("%5d", A[i]);
  }

  mergeSort(A, 0, 9);

  printf("\nAfter sorted: ");
  for(i = 0; i < 10; i++){
    printf("%5d", A[i]);
  }
  printf("\n");
}
