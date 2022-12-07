#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  if(argc != 4){
    printf("Wrong Syntax! Should be: sde <parameter> <parameter> <parameter>");
    return 1;
  }

  double a, b, c;
  double delta;
  a = atof(argv[1]);
  b = atof(argv[2]);
  c = atof(argv[3]);

  /*Solve the equation*/
  if(a == 0){
    if(b == 0){
      if(c == 0){
	printf("Equation has countless roots!");//Pt vo so nghiem
      }
      else{
	printf("Equation has no root!");//Pt vo nghiem
      }
    }
    else{
      printf("The equation has only one root: x = %.2lf", -c/b);
    }
  }
  else{
    delta = b*b - 4*a*c;
    if(delta > 0){
    printf("Equation %.2lfx^2 + %.2lfx + %.2lf = 0 has two roots: x1 = %.2lf, x2 = %.2lf", a, b, c, (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
    }
    else if(delta == 0){
      printf("Equation %.2lfx^2 + %.2lfx + %.2lf = 0 has a double root: x1 = x2 = %.2lf", a, b, c-b/(2*a));//Nghiem kep
    }
    else{
      printf("Equation %.2lfx^2 + %.2lfx + %.2lf = 0 has no root!", a, b, c);
    }
  }

  return 0;
}
