/*
Thu vien: Ngan xep (stack) dung mang so nguyen
Nhuoc diem: kho lam viec voi >2 ngan xep
*/

#include<stdio.h>

#define MAX 50
typedef int elementtype;
typedef elementtype StackType[MAX]; //Dinh nghia kieu StackType la 1 mang gom MAX phan tu kieu elementtype

int top;//Vi lam viec voi mang -> top luon la kieu int

/*Top tro toi vi tri top tuong lai (VD: a[0] -> top = 1)*/

/*---Khoi tao---*/
void initialize(StackType stack){
  top = 0;//Con tro tro toi vi tri top tuong lai
}

/*---Kiem tra xem stack co rong hay ko---*/
int isEmpty(StackType stack){
  return top == 0;
}

/*---Kiem tra xem stack co full hay ko---*/
int isFull(StackType stack){
  return top == MAX;
}

/*---Them 1 gia tri vao stack---*/
void push(elementtype el, StackType stack){
  if(isFull(stack)){
    printf("Stack overflow");
  }
  else{
    stack[top] = el;
    top += 1;
  }
}

/*---Rut 1 gia tri tren cung (top) ra khoi stack---*/
elementtype pop(StackType stack){
  if(isEmpty(stack)){
    printf("Stack underflow");
  }
  else{
    //    elementtype X = stack[top-1];//Vi top tro toi top tuong lai
    top = top - 1;
    return stack[top];
  }
}

/*---Xem gia tri top cua stack (khong rut ra)---*/
elementtype peek(StackType stack){
  if(isEmpty(stack)){
    printf("Stack underflow");
    return -999999;
  }
  else return stack[top-1];
}
