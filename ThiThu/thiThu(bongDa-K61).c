#include"singleLinkedList(BienCucBo).h"

void inThongTin(elementType tmp, node **root, node **cur, node **prev){
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }
  
  //elementType tmp;
  

  int n;//So doi bong
  fscanf(fptr, "%d", &n);
  int count = 0;
  printf("%-5s%-20s%-10s%-14s%-14s\n", "ID", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
  while(count < n){
    fscanf(fptr, "%d\t%[^\n]s", &tmp.id, tmp.ten);
    insertAtHead(tmp, root, cur, prev);
    count++;
  }

  traverseList(*root);
  fclose(fptr);
}

void inLichThiDau(node **root, node **cur, node **prev){
  int n; //So doi bong
  int i; //So thu tu vong dau
  int doi1, doi2;
  elementType tmp;
  
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }
  int count  = 0;
  char str[100];

  printf("\t---LICH THI DAU---\n");
  
  fscanf(fptr, "%d", &n);

  //Dua con tro file den vi tri "Vong 1"
  while(count <= n){
    fgets(str, 30, fptr);
    count++;
  }

  node* p;
  count = 0;
  while(count < n-1){
    fscanf(fptr, "Vong %d\n", &i);
    printf("Vong %d\n", i);

    fscanf(fptr, "%d\t%d\n", &doi1, &doi2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = *root; p != NULL; p = p->next){
      if(doi2 == p->element.id)
	printf("%s\n", p->element.ten);
    }
    
    fscanf(fptr, "%d\t%d\n", &doi1, &doi2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = *root; p != NULL; p = p->next){
      if(doi2 == p->element.id)
	printf("%s\n", p->element.ten);
    }
    count++;
    printf("\n");
  }
  
  fclose(fptr);
}

void capNhatKetQua(node **root, node **cur, node **prev){
  printf("\t---CAP NHAT KET QUA VONG DAU---\n");
  int n;
  int i = 1;
  int count = 0;
  int ketQua1, ketQua2;
  node *p;
  char str[100];
  int doi1, doi2;
  
  FILE* fptr = fopen("bongda.txt", "r");
  if(fptr == NULL){
    printf("Cannot open bongda.txt!\n");
    return;
  }
  
  fscanf(fptr, "%d", &n);
  //Dua con tro file den vi tri "Vong 1"
  while(count <= n){
    fgets(str, 30, fptr);
    count++;
  }
  
  count = 0;
  while(count < n-1){
    fscanf(fptr, "Vong %d\n", &i);
    printf("Cap nhat ket qua Vong %d: \n", i);

    fscanf(fptr, "%d\t%d\n", &doi1, &doi2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id)
	printf("%s - ", p->element.ten);
    }
    
    for(p = *root; p != NULL; p = p->next){
      if(doi2 == p->element.id)
	printf("%s: ", p->element.ten);
    }

    //Cap nhat ket qua tran dau
    scanf("%d - %d", &ketQua1, &ketQua2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id){ //Cap nhat so ban thang + thua cua doi 1
	p->element.soBanThang += ketQua1;
	p->element.soBanThua += ketQua2;
      }
      if(doi2 == p->element.id){ //Cap nhat so ban thang + thua cua doi 2
	p->element.soBanThang += ketQua2;
	p->element.soBanThua += ketQua1;
      }

      //Tinh diem cho cac doi
      if(ketQua1 < ketQua2){
	if(doi2 == p->element.id)
	  p->element.diem += 3;
      }

      if(ketQua1 > ketQua2){
	if(doi1 == p->element.id)
	  p->element.diem += 3;
      }

      if(ketQua1 == ketQua2){
	if(doi1 == p->element.id)
	  p->element.diem += 1;
	if(doi2 == p->element.id)
	  p->element.diem += 1;
      }
    }
    
    fscanf(fptr, "%d\t%d\n", &doi1, &doi2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id)
	printf("%s - ", p->element.ten);
    }

    for(p = *root; p != NULL; p = p->next){
      if(doi2 == p->element.id)
	printf("%s: ", p->element.ten);
    }

    //Cap nhat ket qua tran dau
    scanf("%d - %d", &ketQua1, &ketQua2);
    for(p = *root; p != NULL; p = p->next){
      if(doi1 == p->element.id){ //Cap nhat so ban thang doi 1
	p->element.soBanThang += ketQua1;
	p->element.soBanThua += ketQua2;
      }
      if(doi2 == p->element.id){ //Cap nhat so ban thang doi 2
	p->element.soBanThang += ketQua2;
	p->element.soBanThua += ketQua1;
      }

      //Tinh diem cho cac doi
      if(ketQua1 < ketQua2){
	if(doi2 == p->element.id)
	  p->element.diem += 3;
      }

      if(ketQua1 > ketQua2){
	if(doi1 == p->element.id)
	  p->element.diem += 3;
      }

      if(ketQua1 == ketQua2){
	if(doi1 == p->element.id)
	  p->element.diem += 1;
	if(doi2 == p->element.id)
	  p->element.diem += 1;
      }
    }
    
    count++;
    i++;
  }

  printf("%-5s%-20s%-10s%-14s%-14s\n", "ID", "Tendoibong", "Diem", "Sobanthang", "Sobanthua");
  traverseList(*root);
  
  fclose(fptr);
}

void inCacDoiDiemThapNhat(node **root, node **cur, node **prev){
  node *p;
  node *k;
  int min = (*root)->element.diem;

  printf("\t---CAC DOI CO DIEM THAP NHAT---\n");
  //Tim diem thap nhat
  for(p = *root; p->next != NULL; p = p->next){
    min = min < (p->next)->element.diem ? min : (p->next)->element.diem;
  }

  //Tim cac doi co so diem = min
  p = *root;
  while(p != NULL){
    if(p->element.diem == min){
      displayNode(p);
      *cur = p;
      //Tim prev
      if(p != *root){
	for(k = *root; k->next != p; k = k->next){
	  *prev = k;
	}
      }
      else{
	*prev = NULL;
      }
    
      p = p->next;//Thay doi p truoc roi moi xoa
      
      deleteCurrentElement(&(*root), &(*cur), &(*prev));
      
    }
    else{
      p = p->next;
    }
  }

  printf("\n\t---CAC DOI CON LAI LA---\n");
  traverseList(*root);
}

int main(){
  char choice;
  node *root = NULL, *cur = NULL, *prev = NULL;
  elementType tmp;
  //Khoi tao
  tmp.id = 0;
  strcpy(tmp.ten, "\0");
  tmp.diem = 0;
  tmp.soBanThang = 0;
  tmp.soBanThua = 0;

  int mark = 0; //Bien danh dau xem da tung chon option 1 chua
  
  while(1){
    printf("           ---MENU---\n"
	   "|1. In thong tin cac doi bong.  |\n"
	   "|2. In thong tin lich thi dau.  |\n"
	   "|3. Cap nhat ket qua vong dau.  |\n"
	   "|4. Thong ke.                   |\n"
	   "|5. Thoat.                      |\n");

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
      inThongTin(tmp, &root, &cur, &prev);
      break;
    }

    case '2':{
      inLichThiDau(&root, &cur, &prev);
      break;
    }

    case '3':{
      capNhatKetQua(&root, &cur, &prev);
      break;
    }

    case '4':{
      inCacDoiDiemThapNhat(&root, &cur, &prev);
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
