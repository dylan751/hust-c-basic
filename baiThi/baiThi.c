#include"baiThi.h"

void napDuLieu(node** root, node** cur, node** prev){
  FILE* fptr = fopen("log.txt", "r");
  if(fptr == NULL){
    printf("Khong the mo file log.txt!\n");
    return;
  }

  elementType tmp;
  
  while(fscanf(fptr, "%s %d %d\n", tmp.ten, &tmp.gio, &tmp.phut) != EOF){
    insertAfterCurrent(tmp, &(*root), &(*cur), &(*prev));
  }
  
  printf("\nDoc du lieu thanh cong!\n");
  
  fclose(fptr);
}

void inLichSu(node* root, node* cur, node* prev){
  printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
  traverseList(root);
}

void timKiemLichSuDiChuyen(node* root, node* cur, node* prev){
  char diaDiem[40];
  node* p;
  node* q;
  int count = 0;//Dem so lan nguoi ta den dia diem do
  int i = 0;
  
  printf("Nhap vao ten dia diem: ");
  scanf("%s", diaDiem);

  
  for(p = root; p != NULL; p = p->next){
    if(strcmp(p->element.ten, diaDiem) == 0){
      count++;
    }
  }
  
  
  if(count == 0){ //Neu ko co dia diem
    printf("Ban chua toi dia diem do!\n");
    return;
  }

  if(count == 1){
     for(p = root; p != NULL; p = p->next){
       if(strcmp(p->element.ten, diaDiem) == 0){
	 printf("%d:%d\n", p->element.gio, p->element.phut);
       }
     }
  }

  if(count > 1){
    for(p = root; p != NULL; p = p->next){
      if(strcmp(p->element.ten, diaDiem) == 0){
	if(i < count-1){
	  printf("%d:%d, ", p->element.gio, p->element.phut);
	  i++;
        }
	else
	  printf("%d:%d\n", p->element.gio, p->element.phut);
      }
    }
  }
  
}

void timKiemThongTin(node* root, node* cur, node*prev){
  int g, p;
  
  printf("Nhap vao gio: ");
  scanf("%d", &g);
  while(g < 0 || g >= 24){
    printf("0 <= gio < 24! Nhap lai: ");
    scanf("%d", &g);
  }
  
  printf("Nhap vao phut: ");
  scanf("%d", &p);
  while(p < 0 || p >= 60){
    printf("0 <= phut < 60! Nhap lai: ");
    scanf("%d", &p);
  }

  node* q;
  
  q = root;
  while(q != NULL){
    prev = q;
    q = q->next;

    if(g < 6){
      printf("Khong tim thay lich su di chuyen!\n");
      return;
    }
    if(g == 6){
      if(p < 12){
	printf("Khong tim thay lich su di chuyen!\n");
	return;
      }
    }
    
    if(g == q->element.gio && p == q->element.phut){
       printf("%s\n", q->element.ten);
       break;
    }
    
    if(g < q->element.gio){
      printf("%s\n", prev->element.ten);
      break;
    }

    if(g == q->element.gio){
      if(p < q->element.phut){
	printf("%s\n", prev->element.ten);
	break;
      }
    }
    
    if(q->next == NULL){
      printf("%s\n", q->element.ten);
      q = prev;
      break;
    }
  }
}

void truyVet(node* root, node* cur, node* prev){
  int g, p;
  char diaDiem[40];

  printf("Nhap dia diem benh nhan: ");
  scanf("%s", diaDiem);

  printf("Nhap vao gio: ");
  scanf("%d", &g);
  while(g < 0 || g >= 24){
    printf("0 <= gio < 24! Nhap lai: ");
    scanf("%d", &g);
  }
  
  printf("Nhap vao phut: ");
  scanf("%d", &p);
  while(p < 0 || p >= 60){
    printf("0 <= phut < 60! Nhap lai: ");
    scanf("%d", &p);
  }
  
  node* q;

  for(q = root; q != NULL; q = q->next){
    if(strcmp(q->element.ten, diaDiem) == 0){
      if(q->next != NULL){
	if(g > q->element.gio){
	  if(g == (q->next)->element.gio){
	    if(p < (q->next)->element.phut){
	      printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
	      return;
	    }
	    
	    printf("Lich su di chuyen cua ban OK!\n");
	    
	  }
	}
	else if(g == q->element.gio){
	  if(p > q->element.phut && p < (q->next)->element.phut){
	    printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
	  }
	}
	else if(g < q->element.gio){
	  printf("Lich su di chuyen cua ban OK!\n");
	}

      }
    }
  }
  
  if(strcmp(diaDiem, "Nha_rieng") == 0){//Truong hop cuoi danh sach
    if(g > 20){
      if(g > 21){
	printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
      }
      
      if(g == 21){
	if(p >= 50){
	  printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
	}
	else{
	  printf("Lich su di chuyen cua ban OK!\n");
	}
      }
      if(g < 21){
	printf("Lich su di chuyen cua ban OK!\n");
      }
    }
  }
}

int main(){
  char choice;
  node* root;
  node* cur;
  node* prev;
  
  while(1){
    printf("                   ---MENU---\n"
	   "|1. Nap du lieu log lich su di chuyen.           |\n"
	   "|2. In ra lich su di chuyen.                     |\n"
	   "|3. Tim kiem lich su di chuyen theo dia diem.    |\n"
	   "|4. Tim kiem thong tin di chuyen theo thoi gian. |\n"
	   "|5. Kiem tra truy vet moi nhat.                  |\n"
	   "|6. Thoat.                                       |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '6' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    switch(choice){
      case '1':{
        napDuLieu(&root, &cur, &prev);
        break;
      }

      case '2':{
        inLichSu(root, cur, prev);
        break;
      }

      case '3':{
        timKiemLichSuDiChuyen(root, cur, prev);
        break;
      }

      case '4':{
        timKiemThongTin(root, cur, prev);
        break;
      }

      case '5':{
        truyVet(root, cur, prev);
        break;
      }

      case '6':{
        deleteAllNode(&root);
        exit(0);
        break;
      }
    }
  }
  return 0;
}

