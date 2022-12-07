#include "BST_For_HW3.h"
#include "menu_func.c"
//#include "heapSort_For_HW3.c"

int main(){
  int ch;
  while (1){
    printf("           ---MENU---               \n"
	   "|1. Import data from PhoneDB.txt.  |\n"
	   "|2. Import data from PhoneDB.dat.  |\n"
	   "|3. Add phone model.               |\n"
	   "|4. Delete.                        |\n"
	   "|5. Update.                        |\n"
	   "|6. Searching.                     |\n"
	   "|7. Displaying.                    |\n"
	   "|8. Save to PhoneDB.dat.           |\n"
	   "|9. Heapsort.                      |\n"
	   "|10. Exit.                         |\n");
    printf("Input your choice: ");
    scanf("%d%*c", &ch);
    switch (ch){
    case 1:
      importFromTxt();
      break;

    case 2:
      importFromDat();
      break;

    case 3:
      addPhoneModel();
      break;

    case 4:
      deleteModel();
      break;

    case 5:
      update();
      break;

    case 6:
      searching();
      break;

    case 7:
      display();
      break;

    case 8:
      saveTreeToDat("PhoneDB.dat");
      break;

    case 9:{
      //sort();
      FILE* fptr = fopen("PhoneDB.dat", "rb");
      int count; //count the number of lines in file
      int i;
      
      if(fptr == NULL){
	printf("Cannot open PhoneDB.dat!\n");
	return -1;
      }
      
      fseek(fptr, 0, SEEK_END);
      count = ftell(fptr)/sizeof(DataType);
      rewind(fptr);
      
      DataType arr[count+1];
      fread(arr+1, sizeof(DataType), count, fptr);//Bo qua phan tu arr[0]
      
      heapsort(arr, count);
      fclose(fptr);
      break;
    }
      
    case 10:{
      printf("\tBye! Bye!\n");
      Free();
      exit(0);
      break;
    }
      
    default:
      perror("Choice must be [1, 10]!Input again: ");
      scanf("%d", &ch);
      break;
    }
  }
}
