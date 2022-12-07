#include"BST_For_HW1.h"

treeType root = NULL;

void importFromText(FILE* fptr){
  elementType tmp;

  while(fscanf(fptr, "%s %s", tmp.english, tmp.vietnam) != EOF){
    insertNode(tmp, &root);
  }
}

void printData(){
  printf("---DATA---\n");
  inOrderPrint(root);
}

void searching(){
  char key[30];
  printf("---LOOK UP FOR WORD---\n");
  printf("Input the english word you want to search: ");
  scanf("%s", key);

  if(search(key, root) == NULL){
    printf("Cannot find the word you want!\n");
  }
  else
    printf("%15s%15s\n", search(key, root)->element.english, search(key, root)->element.vietnam);
}

elementType addingWord(){
  elementType tmp;
  printf("---ADDING WORD---\n");
  printf("Input the English word: ");
  scanf("%s", tmp.english);
  __fpurge(stdin);
  printf("Input the Vietnamese meaning: ");
  scanf("%s", tmp.vietnam);

  insertNode(tmp, &root);
  return tmp;
}

void deleteWord(){
  keyType key; //Tu muon xoa

  printf("---DELETE WORD---\n");
  printf("Input the English word you want to delete: ");
  scanf("%s", key);

  if(search(key, root) == NULL){
    printf("The word you want to delete doesn't exist!\n");
  }
  else{
    deleteNode(key, &root);
    printf("DELETE SUCCESS!\n");
  }
}

void saveInOrder(treeType root, FILE* fout){
  if(root != NULL){
    saveInOrder(root->left, fout);
    fprintf(fout, "%s %s\n", root->element.english, root->element.vietnam);
    saveInOrder(root->right, fout);
  }
}

void saveToFile(char* fname){
  printf("---SAVE TO FILE TXT---\n");
  FILE* fptr = fopen(fname, "w");
  if(fptr == NULL){
    printf("Cannot open %s!\n", fname);
    return;
  }

  saveInOrder(root, fptr);
  printf("SAVE SUCCESS!\n");
  fclose(fptr);
}
