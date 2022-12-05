#include"doubleLinkedList.h"

void nhapSanPham(){
  elementType SP[100];
  FILE* fptr = fopen("sanpham.txt", "w");
  int i = 0;
  if(fptr == NULL){
    printf("Cannot open sanpham.txt!\n");
    return;
  }
  
  SP[0].maSP = -1;//Khoi tao ban dau. Khong can thiet, xoa cung duoc
  
  while(1){
    printf("Ma san pham: ");
    scanf("%d", &SP[i].maSP);

    if(SP[i].maSP == 0){
      printf("Nhap san pham hoan thanh!\n");
      break;
    }
    
    if(i > 0){
      while(SP[i].maSP <= SP[i-1].maSP){
	printf("Ma san pham sau phai lon hon ma sp truoc! Nhap lai: ");
	scanf("%d", &SP[i].maSP);
      }
    }
   
    __fpurge(stdin);
    printf("Ten san pham: ");
    scanf("%[^\n]s", SP[i].ten);
    printf("Gia san pham: ");
    scanf("%d", &SP[i].gia);
    while(SP[i].gia <= 0){
      printf("Gia phai >0! Nhap lai: ");
      scanf("%d", &SP[i].gia);
    }
	  
    printf("So luong san pham: ");
    scanf("%d", &SP[i].soLuong);
    while(SP[i].soLuong < 0){
      printf("So luong phai >= 0! Nhap lai: ");
      scanf("%d", &SP[i].soLuong);
    }
    printf("\n");


    
    fprintf(fptr, "%-5d%-10d%-5d%-20s\n", SP[i].maSP, SP[i].gia, SP[i].soLuong, SP[i].ten);

   
    i++;
  }
  fclose(fptr);
}

void docTep(doubleList *root, doubleList *tail, doubleList *cur){
  FILE *fptr = fopen("sanpham.txt", "r");
  if(fptr == NULL){
    printf("Cannot open sanpham.txt!\n");
    return;
  }
  char s[100];
  elementType tmp;
  while(fscanf(fptr, "%d\t%d\t%d\t%[^\n]s\n", &tmp.maSP, &tmp.gia, &tmp.soLuong, tmp.ten) != EOF){
    insertAtTail(tmp, &(*root), &(*tail), &(*cur));
  }

  //In danh sach
  node* p;
  for(p = *root; p != NULL; p = p->next){
    displayNode(p);
  }
      
  fclose(fptr);
}

void sapXep(doubleList *root, doubleList *tail, doubleList *cur){
  node* p;
  node* q;

  elementType tmp;
  
  for(p = *root; p != *tail; p = p->next){
    for(q = *tail; q != p; q = q->prev){
      if(q->element.gia < q->prev->element.gia){
	tmp = q->element;
	q->element = q->prev->element;
	q->prev->element = tmp;
      }
    }
  }
  node* i;
  for(i = *root; i != NULL; i = i->next){
    displayNode(i);
  }
}

double tongTien(doubleList *root, doubleList *tail, doubleList *cur){
  double sum;
  node* p;
  for(p = *root; p != NULL; p = p->next){
    sum += p->element.gia * p->element.soLuong;
  }

  printf("Tong tien = %.2lf\n", sum);

  return sum;
}

int main(){
  char choice;
  doubleList root, cur, tail;
  makeNullList(&root, &tail, &cur);
  while(1){
    printf("           ---MENU---\n"
	   "|1. Nhap san pham.               |\n"
	   "|2. Doc tep.                     |\n"
	   "|3. Sap xep.                     |\n"
	   "|4. Tinh tong so tien.           |\n"
	   "|5. Dem nhom san pham trung gia. |\n"
	   "|6. Ten trung nhau.              |\n"
	   "|7. Thoat.                       |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '7' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1':{
      nhapSanPham();
      break;
    }

    case '2':{
      docTep(&root, &tail, &cur);
      break;
    }

    case '3':{
      sapXep(&root, &tail, &cur);
      break;
    }

    case '4':{
      tongTien(&root, &tail, &cur);
      break;
    }

    case '5':{
      
      break;
    }

    case '6':{

      break;
    }

    case '7':{
      //system("clear");//Xoa man hinh luon
      exit(0);
      break;
    }

    default: {
      printf("Invalid syntax! Input your choice again: ");
      __fpurge(stdin);
      scanf("%c", &choice);
      break;
    }
    }
  }
  return 0;
}
