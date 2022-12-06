#include<stdio.h>
//CHUA HOAN THIEN
//Sap xep tu to chuc

//Cach 1: Tim thay key -> dua len dau mang
int search1(int key, int r[], int n){
  int i, j;
  int tmp;
  for(i - 0; i < n-1 && r[i] != key; i++){
    if(key == r[i]){
      if(i>0){
	tmp = r[i];
	for(j = i; j > 0; j--) r[j] = r[j-1];
	r[0] = tmp;
      }
    return i;
    }
    else{
      return -1;
    }
  }
}

//Cach 2: Tranpose (tim thay key -> doi cho key vs phan tu truoc no
int search2(int key, int r[], int n){
  int i;
  int tmp;
  for(i = 0; i <= n-1 && r[i] != key; i++){
    if(key == r[i]){
      if(i > 0){
	//Hoan doi vi tri key voi phan tu dung truoc no
	tmp = r[i];
	r[i] = r[i-1];
	r[--i] = tmp;
      }
      for(i = 0; i < n; i++){
	printf("%5d", r[i]);
      }
      return i;
    } else return -1;
  }
}

int main(){
  int i, n;
  int A[100];
  int key;

  printf("Nhap n: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    printf("A[%d]: ", i);
    scanf("%d", &A[i]);
  }
  printf("Key = ");
  scanf("%d", &key);
  search2(key, A, n);

  
}

