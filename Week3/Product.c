#include<stdio.h>

#define CONSTANT 100

typedef struct{
  int ID;
  char name[CONSTANT];
  double price;
} product;

int main(){
  product product_array[CONSTANT];
  char file_name[CONSTANT] = "product.txt";
  FILE* fptr = fopen(file_name, "r");

  /*Goi y, phai ve hoan thien not*/
  while(fscanf(fptr, "%d%s%lf", &product_arr[i].ID, &product_arr[i].name, &product_arr[i].price) != EOF);

  printf("%%%, arr[i].ID", arr[i].name, arr[i].price);
}
