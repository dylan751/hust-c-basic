#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  float height, width;
 
  if(argc != 3){
    printf("Wrong Syntax! Should be: <height><width>");
    return 1;
  }

  height = atof(argv[2]);
  width = atof(argv[1]);

  printf("The rectangle's area is %f\n", width * height);
  printf("The rectangle's perimeter is %f\n", 2*(width + height));

  return 0;
}
