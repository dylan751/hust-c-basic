#include"thiCaSang.h"

int loadDataFile(int sum, node** root, node** cur, node** prev){
  int N;//so luong may
  char filename[30];
  elementType tmp;
  
  printf("Input file name: ");
  scanf("%s", filename);
  
  FILE* fptr = fopen(filename, "r");
  if(fptr == NULL){
    printf("File khong ton tai!\n");
    return -1;
  }
  
  fscanf(fptr, "%d", &N);
  
  
  int i;
  int count = 0;

  for(i = sum; i < N+sum; i++){
    tmp.id = i+1;
    fscanf(fptr, "%s %d\n", tmp.CPU, &tmp.RAM);
    insertAfterCurrent(tmp, &(*root), &(*cur), &(*prev));
    count++;
  }
  printf("So may vua them moi: %d\n", count);  
  
  fclose(fptr);
  return count;
}

void updateCPU(int N, node** root, node** cur, node** prev){
  int ID;
  char newCPU[30];
  node* p;
  
  printf("Nhap ID may muon nhap: ");
  scanf("%d", &ID);
  while(ID < 1 || ID > N){
    printf("ID>1 va <%d! Nhap lai ID: ", N);
    scanf("%d", &ID);
  }
  
  __fpurge(stdin);
  printf("Nhap ten CPU moi: ");
  scanf("%s", newCPU);
  if(strcmp(newCPU, "STOP") == 0){
    printf("%-10s%-10s\n", "CPU", "RAM");
    traverseList(*root);
    return;
  }

  for(p = *root; p != NULL; p = p->next){
    if(p->element.id == ID){
      strcpy(p->element.CPU, newCPU);
    }
  }
  
  while(ID < N){
    ID++;
    printf("ID = %d\n", ID);
    __fpurge(stdin);
    printf("Nhap ten CPU cho may co ID %d: ", ID);
    scanf("%s", newCPU);

    if(strcmp(newCPU, "STOP") == 0){
      printf("Dung chuc nang!\n");
      break;
    }
    
    for(p = *root; p != NULL; p = p->next){
      if(p->element.id == ID){
	strcpy(p->element.CPU, newCPU);
      }
    }
  }

  printf("%-10s%-10s\n", "CPU", "RAM");
  traverseList(*root);
  
}

void updateRAM(int N, node** root, node** cur, node** prev){
  int ID;
  int newRAM;
  node* p;
  
  printf("Nhap ID may muon nhap: ");
  scanf("%d", &ID);
  while(ID < 1 || ID > N){
    printf("ID>1 va <%d! Nhap lai ID: ", N);
    scanf("%d", &ID);
  }
  
  __fpurge(stdin);
  printf("Nhap RAM moi: ");
  scanf("%d", &newRAM);

  while(newRAM%2 != 0 && newRAM != 1){
    printf("RAM khong hop le! Nhap lai: ");
    scanf("%d", &newRAM);
  }
  
  for(p = *root; p != NULL; p = p->next){
    if(p->element.id == ID){
      p->element.RAM = newRAM;
    }
  }
  
  while(ID < N){
    ID++;
    printf("ID = %d\n", ID);
    __fpurge(stdin);
    printf("Nhap RAM moi cho may co ID %d: ", ID);
    scanf("%d", &newRAM);

    for(p = *root; p != NULL; p = p->next){
      if(p->element.id == ID){
	p->element.RAM = newRAM;
      }
    }
  }

  printf("%-10s%-10s\n", "CPU", "RAM");
  traverseList(*root);
  
}

void search(node* root, node* cur, node* prev){
  char x[30];
  node* p;
  int i;
  int mark = 0;
  int ketQua = 0;
  printf("Nhap vao thong tin may ban muon tim: ");
  scanf("%s", x);

  //Neu la ki tu hop le
  if(x[0] == 'i' || x[0] == 'I'){
    for(p = root; p != NULL; p = p->next){
      if(strcasecmp(p->element.CPU, x) == 0){
	printf("%-10s%-10d\n", p->element.CPU, p->element.RAM);
	mark++;
      }
    }
  }
  else if(x[0] < '0' || x[0] > '9'){//Ki tu khong hop le
    printf("Xau ki tu khong hop le!\n");
    return;
  }
  else{//Neu la so
    for(i = 0; i < strlen(x); i++){//Chuyen ve dang in
      ketQua *= 10;
      ketQua += x[i] - '0';
      
    }

    
    if(ketQua%2 != 0 && ketQua != 1){
      printf("So nhap vao khong hop le!\n");
      return;
    }
    else{
      for(p = root; p != NULL; p = p->next){
	if(p->element.RAM == ketQua){
	  printf("%-10s%-10d\n", p->element.CPU, p->element.RAM);
	  mark++;
	}
      }
    }
  }

  
  
  if(mark == 0){
    printf("Khong tim thay!\n");
  }
}


int main(){
  char choice;
  node* root;
  node* cur;
  node* prev;

  int sum = 0;//tong so may
  
  while(1){
    printf("           ---MENU---\n"
	   "|1. Load data files.  |\n"
	   "|2. Update CPU info.  |\n"
	   "|3. Updata RAM info.  |\n"
	   "|4. Search.           |\n"
	   "|5. Quit.             |\n");

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
      if(sum > 20){
	printf("Danh sach da day, khong them duoc!\n");
	break;
      }
      
      sum += loadDataFile(sum, &root, &cur, &prev);
      
      break;
    }

    case '2':{
      updateCPU(sum, &root, &cur, &prev);
      break;
    }

    case '3':{
      updateRAM(sum, &root, &cur, &prev);
      break;
    }

    case '4':{
      search(root, cur, prev);
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
