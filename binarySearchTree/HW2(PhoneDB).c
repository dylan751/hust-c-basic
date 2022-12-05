#include"binarySearchTree.h"

elementType getData(){
  elementType new;
  __fpurge(stdin);
  printf("Input phone model: ");
  scanf("%s", new.model);

  __fpurge(stdin);
  printf("Input phone memory: ");
  scanf("%s",  new.memory);

  printf("Input phone size: ");
  scanf("%lf", &new.size);

  printf("Input phone price: ");
  scanf("%lf", &new.price);
  return new;
}

void importFromDat(treeType *root){
  FILE* fptr = fopen("PhoneDB.dat", "rb");
  if(fptr == NULL){
    printf("Cannot open PhoneDB.dat!\n");
    return;
  }
  elementType tmp;
  
  while((int*)fread(&tmp, sizeof(elementType), 1, fptr) != NULL){
    insertNode(tmp, &(*root));
  }

  fclose(fptr);
}

void importFromTxt(treeType *root){
  FILE* fptr = fopen("PhoneDB.txt", "r");
  if(fptr == NULL){
    printf("Cannot open PhoneDB.txt!\n");
    return;
  }
  elementType tmp;

  while(!feof(fptr)){
    fscanf(fptr, "%s\t%s\t%lf\%lf\n", tmp.model, tmp.memory, &(tmp.size), &(tmp.price));
    insertNode(tmp, &(*root));
  }
  
  fclose(fptr);
}

void display(treeType root){
  inOrderPrint(root);
}

void addNewPhone(treeType *root){
  elementType tmp;
  tmp = getData();
  insertNode(tmp, &(*root));
}

void deletePhone(treeType *root){
  char* key;
  key = (char*)malloc(sizeof(char));
  printf("Input the phone model you want to delete: ");
  scanf("%s", key);

  if(search(key, *root) == NULL){
    printf("There aren't any phone match your need!\n");
    return;
  }
  else{
    deleteNode(search(key, *root)->element, &(*root));
  }
  
  free(key);
}

void updatePhone(treeType *root){
  char* key;
  key = (char*)malloc(sizeof(char));
  printf("Input the phone model you want to update: ");
  scanf("%s", key);

  if(search(key, *root) == NULL){
    printf("There aren't any phone match your need!\n");
    return;
  }
  else{
    deleteNode(search(key, *root)->element, &(*root));
    addNewPhone(&(*root));
  }

  free(key);
}

void searching(treeType root){
   char* key;
  key = (char*)malloc(sizeof(char));
  printf("Input the phone model you want to update: ");
  scanf("%s", key);

  if(search(key, root) == NULL){
    printf("There aren't any phone match your need!\n");
    return;
  }
  else{
    elementType tmp;
    tmp = search(key, root)->element;
    printf("%-25s%-10s%-10.2lf%-10.2lf\n", tmp.model, tmp.memory, tmp.size, tmp.price);
  }

  free(key);
}

void saveInOrder(treeType root, FILE* fout){
  if(root != NULL){
    saveInOrder(root->left, fout);
    fwrite(&(root->element), sizeof(elementType), 1, fout);
    saveInOrder(root->right, fout);
  }
}

void saveToDat(treeType root){
  FILE* fout = fopen("PhoneDB.dat", "wb");
  if(fout == NULL){
    printf("Cannot open PhoneDB.dat!\n");
    return;
  }
  
  saveInOrder(root, fout);
    
  fclose(fout);
}

int main(){
  char choice;
  treeType root;
  makeNullTree(&root);
  
  while(1){
    printf("           ---MENU---\n"
	   "|1. Import from PhoneDB.dat.  |\n"
	   "|2. Import from PhoneDB.txt.  |\n"
	   "|3. Add new phone.            |\n"
	   "|4. Delete phone.             |\n"
	   "|5. Update phone.             |\n"
	   "|6. Searching for phone.      |\n"
	   "|7. Displaying Database.      |\n"
	   "|8. Save to PhoneDB.dat.      |\n"
	   "|9. Exit                      |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice > '9' || choice < '1'){
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1':{
      importFromDat(&root);
      break;
    }

    case '2':{
      importFromTxt(&root);
      break;
    }

    case '3':{
      addNewPhone(&root);
      break;
    }

    case '4':{
      deletePhone(&root);
      break;
    }

    case '5':{
      updatePhone(&root);      
      break;
    }

    case '6':{
      searching(root);
      break;
    }

    case '7':{
      display(root);
      break;
    }

    case '8':{
      saveToDat(root);
      break;
    }

    case '9':{

      exit(0);
      break;
    }
    }
  }
  return 0;
}
