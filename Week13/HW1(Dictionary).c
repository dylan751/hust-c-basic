#include<stdio_ext.h>
#include"menu.c"

int main(){
  char choice;
  FILE* fptr;
  
  fptr = fopen("dic.txt", "r");
  if(fptr == NULL){
    printf("Cannot open dic.txt!\n");
    return -1;
  }
  
  while(1){
    printf("       ---MENU---\n"
	   "|1. Import from txt.   |\n"
	   "|2. Print data.        |\n"
	   "|3. Searching meaning. |\n"
	   "|4. Adding word.       |\n"
	   "|5. Delete word.       |\n"
	   "|6. Save data to file  |\n"
	   "|7. Exit.              |\n");
    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);
    while(choice < '1' || choice > '7'){
      printf("Choice must be [1,7]! input again: ");
      __fpurge(stdin);
      scanf("%c", &choice);
    }

    switch(choice){
    case '1':{
      importFromText(fptr);
      fclose(fptr);
      break;
    }
      
    case '2':{
      printData();
      break;
    }
      
    case '3':{
      searching();
      break;
    }
      
    case '4':{
      addingWord();
      break;
    }
      
    case '5':{
      deleteWord();
      break;
    }
      
    case '6':{
      saveToFile("dic.txt");
      break;
    }

    case '7':{
      exit(0);
      break;
    }

    default:{
      __fpurge(stdin);
      printf("Choice must be [1, 7]! Input again: ");
      scanf("%c", &choice);
    }
    }
  }
  fclose(fptr);
}
