#include<stdio.h>
#include<math.h>

typedef struct point{
  double x;
  double y;
}point_t;

typedef struct circle{
  point_t center;
  double radius;
}circle_t;

void input_info(point_t A, circle_t circle){
  printf("Input the coordinates of the point A(x, y): ");//Nhap toa do cua diem A
  scanf("%lf%lf", &A.x, &A.y);

  printf("Input the coordinates of the center of the circle: ");//Nhap toa do tam duong tron
  scanf("%lf%lf", &circle.center.x, &circle.center.y);

  printf("Input the radius: ");
  scanf("%lf", &circle.radius);
}

int is_in_circle(point_t p, circle_t circle){
  double distance;

  distance = sqrt(pow(p.x - circle.center.x, 2) + pow(p.y - circle.center.y, 2));

  if(distance < circle.radius){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  point_t A;       //toa do diem A 
  circle_t circle; //thong so cua duong tron
  input_info(A, circle);

  if(is_in_circle(A, circle)){
    printf("A is inside the circle");
  }
  else{
    printf("A is outside the circle");
  }
  return 0;
}
