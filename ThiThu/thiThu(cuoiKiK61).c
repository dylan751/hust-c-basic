#include"cuoiKiK61.h"

void inThongTinDoiBong(node** root, node** cur, node** prev){
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }

  int N;//So doi bong
  elementType tmp;
  int count = 0;//bien dem
  fscanf(fptr, "%d\n", &N);

  //Khoi tao tmp
  tmp.diem = 0;
  tmp.soBanThang = 0;
  tmp.soBanThua = 0;
  
  while(count < N){
    fscanf(fptr, "%d\t%[^\n]s\n", &tmp.id, tmp.ten);
    insertAtHead(tmp, &(*root), &(*cur), &(*prev));
    count++;
  }

  printf("%-5s%-20s%-15s%-15s%-15s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
  traverseList(*root);
  fclose(fptr);
}

void inThongTinLichThiDau(node* root, node* cur, node* prev){
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }

  char str[100];
  int N;//So doi bong
  elementType tmp;
  int count = 0;//bien dem
  int id1, id2;
  fscanf(fptr, "%d\n", &N);

  //Di chuyen con tro den vi tri can thiet
  while(count < N){
    fscanf(fptr, "%d\t%[^\n]s\n", &tmp.id, tmp.ten);
    count++;
  }

  node* p;
  count = 0;
  while(count < N){

    fgets(str, 100, fptr);
    printf("%s", str);

    fscanf(fptr,"%d\t%d\n", &id1, &id2);
    for(p = root; p != NULL; p = p->next){
      if(id1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = root; p != NULL; p = p->next){
      if(id2 == p->element.id)
	printf("%s\n", p->element.ten);
    }

    fscanf(fptr,"%d\t%d\n", &id1, &id2);
    for(p = root; p != NULL; p = p->next){
      if(id1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = root; p != NULL; p = p->next){
      if(id2 == p->element.id)
	printf("%s\n", p->element.ten);
    }
    count++;
  }
  fclose(fptr);
}

void capNhatKetQuaVongDau(node** root, node** cur, node** prev){
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }
  
  char str[100];
  int N;//So doi bong
  elementType tmp;
  int count = 0;//bien dem
  int id1, id2, ketQua1, ketQua2;
  int i = 1;
  fscanf(fptr, "%d\n", &N);

  //Di chuyen con tro den vi tri can thiet
  while(count <= N){
    fscanf(fptr, "%d\t%[^\n]s\n", &tmp.id, tmp.ten);
    count++;
  }

  node* p;
  count = 0;
  while(count < N-1){

    fgets(str, 100, fptr);
    printf("%s", str);

    fscanf(fptr,"%d\t%d\n", &id1, &id2);
    for(p = *root; p != NULL; p = p->next){
      if(id1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = *root; p != NULL; p = p->next){
      if(id2 == p->element.id)
	printf("%s: ", p->element.ten);
    }

    scanf("%d - %d", &ketQua1, &ketQua2);

    for(p = *root; p != NULL; p = p->next){
      //Cap nhat so bang thang, thua, diem so
      if(id1 == p->element.id){
	p->element.soBanThang += ketQua1;
	p->element.soBanThua += ketQua2;

	if(ketQua1 < ketQua2)
	  p->element.diem += 0;
	if(ketQua1 > ketQua2)
	  p->element.diem += 3;
	if(ketQua1 == ketQua2)
	  p->element.diem += 1;
      }
      
      
      if(id2 == p->element.id){
	p->element.soBanThang += ketQua2;
	p->element.soBanThua += ketQua1;
	
	if(ketQua1 < ketQua2)
	  p->element.diem += 3;
	if(ketQua1 > ketQua2)
	  p->element.diem += 0;
	if(ketQua1 == ketQua2)
	  p->element.diem += 1;
      }
    }
    

    fscanf(fptr,"%d\t%d\n", &id1, &id2);
    for(p = *root; p != NULL; p = p->next){
      if(id1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = *root; p != NULL; p = p->next){
      if(id2 == p->element.id)
	printf("%s: ", p->element.ten);
    }

    scanf("%d - %d", &ketQua1, &ketQua2);

    for(p = *root; p != NULL; p = p->next){
      //Cap nhat so bang thang, thua, diem so
      if(id1 == p->element.id){
	p->element.soBanThang += ketQua1;
	p->element.soBanThua += ketQua2;

	if(ketQua1 < ketQua2)
	  p->element.diem += 0;
	if(ketQua1 > ketQua2)
	  p->element.diem += 3;
	if(ketQua1 == ketQua2)
	  p->element.diem += 1;
      }
    
       
      if(id2 == p->element.id){
	p->element.soBanThang += ketQua2;
	p->element.soBanThua += ketQua1;
					  
	if(ketQua1 < ketQua2)
	  p->element.diem += 3;
	if(ketQua1 > ketQua2)
	  p->element.diem += 0;
	if(ketQua1 == ketQua2)
	  p->element.diem += 1;
      }
    }

    printf("%-5s%-20s%-15s%-15s%-15s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
  traverseList(*root);
    count++;
  }

  
  fclose(fptr);
}

void thongKe(node** root, node** cur, node** prev){
  node* p;
  int min;
  printf("Cac doi co diem thap nhat la: \n");
  printf("%-5s%-20s%-15s%-15s%-15s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");

  min = (*root)->element.diem;
  for(p = *root; p != NULL; p = p->next){
    min = min > p->element.diem ? p->element.diem : min;
  }

  for(p = *root; p != NULL; p = p->next){
    if(p->element.diem == min){
      printf("%-5d%-20s%-15d%-15d%-15d\n", p->element.id, p->element.ten, p->element.diem, p->element.soBanThang, p->element.soBanThua);
      *cur = p;
    }
  }

  deleteCurrentElement(&(*root), &(*cur), &(*prev));
  
  printf("Cac doi con lai la: \n");
  printf("%-5s%-20s%-15s%-15s%-15s\n", "Id", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
  traverseList(*root);
}

int main(){
  char choice;
  node* root;
  node* cur;
  node* prev;
  
  while(1){
    printf("           ---MENU---\n"
	   "|1. In thong tin cac doi bong. |\n"
	   "|2. In thong tin lich thi dau  |\n"
	   "|3. Cap nhat ket qua vong dau. |\n"
	   "|4. Thong ke.                  |\n"
	   "|5. Thoat.                     |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '5' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1':{
      inThongTinDoiBong(&root, &cur, &prev);
      break;
    }

    case '2':{
      inThongTinLichThiDau(root, cur, prev);
      break;
    }

    case '3':{
      capNhatKetQuaVongDau(&root, &cur, &prev);
      break;
    }

    case '4':{
      thongKe(&root, &cur, &prev);
      break;
    }

    case '5':{
      exit(0);
      break;
    }

    }
  }
  return 0;
}
