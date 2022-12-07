#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i, n , *p;
  printf("How many numbers do you want to enter: ");
  scanf("%d", &n);

  /* Allocate an int array of the proper size */
  p = (int *)malloc(n * sizeof(int));
  if(p == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }

  /* Get the numbers from the user */
  for(i = 0; i < n; i++){
    printf("Input number %d: ", i+1);
    scanf("%d", &p[i]);
  }

  /* Display them in reverse */
  for(i = n-1; i >= 0; i--){
    printf("%d\t", p[i]);
    printf("\n");
  }

  /* Free the allozated space */
  free(p);
  return 0;
}
