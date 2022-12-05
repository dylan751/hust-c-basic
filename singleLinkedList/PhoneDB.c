#include"ThuVienTruuTuong.h"

void importFromDat(FILE* fin){
  elementtype *tmp;
  elementtype p;
  while((int*)fread(tmp, sizeof(elementtype), 1, fin) != NULL){
    p = *tmp;
    insertAfterCurrent(p);
  }
}

void display(){
  node* p;
  for(p = root; p != NULL; p = p->next){
    displayNode(p);
  }
}

void addNewPhone(){
  elementtype phone;
  char choice;
  while(choice != '3'){
    printf("           ---MENU---\n"
	   "|1. Insert before current.  |\n"
	   "|2. Insert after current.   |\n"
	   "|3. Exit.                   |\n");
    __fpurge(stdin);
    printf("Input you choice: ");
    scanf("%c", &choice);

    while(choice < '1' || choice > '3'){
      __fpurge(stdin);
      printf("Invalid! Input again: ");
      scanf("%c", &choice);
    }
    
    switch(choice){
    case '1':{
      phone = readNode();
      insertBeforeCurrent(phone);
      break;
    }
      
    case '2':{
      phone = readNode();
      insertAfterCurrent(phone);
      break;
    }
    
    }
  }
}


elementtype insertAtPosition(){
  int x, i;
  node* p;
  elementtype tmp;
  printf("Input the position you want to add new phone: ");
  scanf("%d", &x);
  while(x < 0){
    printf("Input a >0 number: ");
    scanf("%d", &x);
  }
  
  tmp = readNode();
  if(x == 0){
    insertAtHead(tmp);
  }
  else{
    p = root;
    for(i = 0; i < x-1; i++){
      p = p->next;
    }
    cur = p;
    insertAfterCurrent(tmp);
  }
  return tmp;
}

void deleteAtPosition(){
  int x, i;
  node* p;
  elementtype tmp;
  printf("Input the position you want to delete phone: ");
  scanf("%d", &x);
  while(x < 0){
    printf("Input a >0 number: ");
    scanf("%d", &x);
  }

  p = root;
  for(i = 0; i < x-1; i++){
    prev = p;
    p = p->next;
  }
  cur = p;
  deleteCurrentElement();
}

void searchAndUpdate(){
  char* x;
  node* p;
  int mark = 0;
  elementtype tmp;
  
  x = (char*)malloc(sizeof(char));
  if(x == NULL){
    printf("Allocation failed!\n");
  }
  
  printf("Input the model that you want to search and update: ");
  scanf("%s", x);

  for(p = root; p != NULL; p = p->next){
    if(strcmp(p->element.model, x) == 0){
      displayNode(p);
      mark++;
      break;
    }
  }
  cur = p;
  
  //Tim prev
  if(cur == root){
    prev = NULL;
  }
  else{
    p = root;
    while(p->next != cur){
      p = p->next;
    }
    prev = p;
  }
  if(mark == 0){
    printf("There aren't any phone that match your model!\n");
    return;
  }
  
  //Update
  printf("\t---UPDATE---\n");
  tmp = readNode();
  deleteCurrentElement();
  insertBeforeCurrent(tmp);

  free(x);
}

void saveToFile(){
  node* p;
  FILE* fout = fopen("PhoneDB.dat", "wb");
  if(fout == NULL){
    printf("Cannot open PhoneDB.dat!\n");
    return;
  }

  for(p = root; p != NULL; p = p->next){
    fwrite(&(p->element), sizeof(elementtype), 1, fout);
  }

  fclose(fout);
}

int main(){
  int choice;
  FILE* fptr = fopen("PhoneDB.dat", "rb");
  if(fptr == NULL){
    printf("Cannot open PhoneDB.dat!\n");
    return -1;
  }
  
  while(1){
    printf("           ---MENU---\n"
	   "|1. Import from PhoneDB.dat.  |\n"
	   "|2. Display.                  |\n"
	   "|3. Add new phone.            |\n"
	   "|4. Insert At Position.       |\n"
	   "|5. Delete At Position.       |\n"
	   "|6. Delete current.           |\n"
	   "|7. Delete first.             |\n"
	   "|8. Search and update.        |\n"
	   "|9. Divide and extract.       |\n"
	   "|10. Reverse list.            |\n"
	   "|11. Save to file.            |\n"
	   "|12. Quit.                    |\n");

    printf("Input your choice: ");
    scanf("%d", &choice);
    

    switch(choice){
    case 1:{
      importFromDat(fptr);
      break;
    }

    case 2:{
      display();
      break;
    }

    case 3:{
      addNewPhone();
      break;
    }

    case 4:{
      insertAtPosition();
      break;
    }

    case 5:{
      deleteAtPosition();
      break;
    }

    case 6:{
      deleteCurrentElement();
      break;
    }

    case 7:{
      deleteFirstElement();
      break;
    }

    case 8:{
      searchAndUpdate();
      break;
    }

    case 9:{

      break;
    }

    case 10:{
      root = reverseList(root);
      break;
    }

    case 11:{
      saveToFile();
      break;
    }
		      
    case 12:{

      exit(0);
      break;
    }

    default:{
      __fpurge(stdin);
      printf("Wrong syntax! Input again: ");
      scanf("%d", &choice);
    }
    }
  }
  fclose(fptr);
  return 0;
}
