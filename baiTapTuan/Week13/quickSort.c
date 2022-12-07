#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int elementType;

void quickSort(elementType list[], int left, int right){
  int pivot;//phan tu chot'
  int i, j;
  elementType temp;
  if(left < right){
    i = left;
    j = right+1;
    pivot = list[left];
    do{
      do i++; while(list[i] < pivot); //tim phan tu > pivot o ben trai
      do j--; while(list[j] > pivot); //tim phan tu < pivot o ben phai
      if(i < j){  //Doi cho 2 phan tu vua tim duoc cho nhau
	temp = list[i];
	list[i] = list[j];
	list[j] = temp;
      }
    }while(i < j);

    //Doi cho cua pivot (now dang o left) ra vi tri thu j (vua tim duoc)
    temp = list[left];
    list[left] = list[j];
    list[j] = temp;

    quickSort(list, left, j-1);  //De quy quickSort voi nua trai
    quickSort(list, j+1, right); //De quy quickSort voi nua phai
  }

}

int main(){
  clock_t t1, t2;
  srand(time(NULL));
  elementType arr[10];
  int i;
  
  for(i = 0; i < 10; i++){
    arr[i] = rand()%100;
  }

  t1 = clock();
  quickSort(arr, 0, 10-1);
  t2 = clock();
  printf("\nThoi gian = %lf\n", (double)(t2 - t1)/CLOCKS_PER_SEC);

  for(i = 0; i < 10; i++){
    printf("%5d", arr[i]);
  }
  
  return 0;
}
