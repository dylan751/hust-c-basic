#include"quanLiThongTinSanPham.h"

void nhapSanPham(){
  FILE* fptr = fopen("sanpham.txt", "w");
  if(fptr == NULL){
    printf("Cannot open file sanpham.txt!\n");
    return;
  }
  int i = 0;//Index
  elementType tmp[100];

  while(1){
    printf("\nNhap ma san pham: ");
    scanf("%d", &tmp[i].maSP);
    if(tmp[i].maSP == 0)
      return;
    
    if(i > 0){
      while(tmp[i].maSP <= tmp[i-1].maSP){
	printf("Ma san pham sau phai lon hon ma san pham truoc! Nhap lai: ");
	scanf("%d", &tmp[i].maSP);
      }
    }
      
    __fpurge(stdin);
    printf("Nhap ten san pham: ");
    scanf("%[^\n]s", tmp[i].ten);
    
    printf("Nhap gia san pham: ");
    scanf("%d", &tmp[i].gia);
    
    printf("Nhap so luong san pham: ");
    scanf("%d", &tmp[i].soLuong);
    
    fprintf(fptr, "%-5d%-10d%-10d%-20s\n", tmp[i].maSP, tmp[i].gia, tmp[i].soLuong, tmp[i].ten);
    
    
    i++;
  }
  
  fclose(fptr);
}

void docTep(node** root, node** cur, node** prev){
  FILE* fptr = fopen("sanpham.txt", "r");
  if(fptr == NULL){
    printf("Cannot open sanpham.txt!\n");
    return;
  }

  char str[100];
  elementType tmp;
  int count;//Dem so dong`
  
  node* new;
  while(fscanf(fptr, "%d\t%d\t%d\t%[^\n]s\n", &tmp.maSP, &tmp.gia, &tmp.soLuong, tmp.ten) != EOF){
    new = insertAfterCurrent(tmp, &(*root), &(*cur), &(*prev));
    printf("%-20p%-5d%-10d%-10d%-20s\n", new, tmp.maSP, tmp.gia, tmp.soLuong, tmp.ten);
  }

  fclose(fptr);
}

void sapXep(node** root, node** cur, node** prev){
  node* p;
  node* q;

  elementType tmp;
  
  for(p = *root; p != NULL; p = p->next){
    for(q = *root; q->next != NULL; q = q->next){
      if(q->element.gia > (q->next)->element.gia){
	tmp = q->element;
	q->element = (q->next)->element;
	(q->next)->element = tmp;
      }
      
    }
  }

  traverseList(*root);
}

void tongTien(node* root, node* cur, node* prev){
  int sum = 0;

  node* p;
  for(p = root; p != NULL; p = p->next){
    sum += p->element.gia * p->element.soLuong;
  }

  printf("Tong tien = %d\n", sum);
}

void demNhomTrungGia(node* root, node* cur, node* prev){
  node* p = root;
  node* q = root;
  int count = 0; //dem so nhom trung gia
  while(p != NULL && q != NULL){
    p = p->next;
    if(p->element.gia == q->element.gia){
      count++;
      p = p->next;
    }
    if(p != NULL)
      while(p->element.gia == q->element.gia){
	p = p->next;
      }

    q = p;
  }

  printf("So nhom san pham trung gia = %d\n", count);
}

void demNhomTrungTen(node* root, node* cur, node* prev){
  node* p = root;
  node* q = root;
  int count = 0; //dem so nhom trung ten
  elementType tmp;
  //Sap xep theo ten
  for(p = root; p != NULL; p = p->next){
    for(q = root; q->next != NULL; q = q->next){
      if(strcmp(q->element.ten, (q->next)->element.ten) > 0){
	tmp = q->element;
	q->element = (q->next)->element;
	(q->next)->element = tmp;
      }
    }
  }
  traverseList(root);
  p = root;
  q = root;
  while(p != NULL && q != NULL){
    p = p->next;
    if(strcmp(p->element.ten, q->element.ten) == 0){
      count++;
      p = p->next;
    }
    if(p != NULL)
      while(strcmp(p->element.ten, q->element.ten) == 0){
	if(p->next != NULL)
	  p = p->next;
      }

    q = p;
  }

  printf("So nhom san pham trung ten = %d\n", count);
}

int main(){
  char choice;
  node* root = NULL;
  node* cur = NULL;
  node* prev = NULL;
  
  while(1){
    printf("             ---MENU---\n"
	   "|1. Nhap san pham.                |\n"
	   "|2. Doc tep.                      |\n"
	   "|3. Sap xep.                      |\n"
	   "|4. Tinh tong tien.               |\n"
	   "|5. Dem nhom san pham trung gia.  |\n"
	   "|6. Kiem tra san pham trung ten.  |\n"
	   "|7. Thoat.                        |\n");

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
      docTep(&root, &cur, &prev);
      break;
    }

    case '3':{
      sapXep(&root, &cur, &prev);
      break;
    }

    case '4':{
      tongTien(root, cur, prev);
      break;
    }

    case '5':{
      demNhomTrungGia(root, cur, prev);
      break;
    }

    case '6':{
      //demNhomTrungTen(root, cur, prev);
      root = reverseList(&root);
      traverseList(root);

      saveToTxt(root, "sanpham.txt");
      break;
    }

    case '7':{
      exit(0);
      break;
    }

    }
  }
  return 0;
}
