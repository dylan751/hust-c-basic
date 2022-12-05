#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

#define MAX 100

typedef struct {
  char model[30];
  double memory_space;
  double screen_size;
  double price;
}phone;

int count_phone(FILE* fptr_in){
  int n = 0;
  char str[MAX];
  while(fgets(str, MAX, fptr_in) != NULL){
    n++;
  }
  
  return n;
}

void change_into_dat(phone *phonearr, FILE *fptr_in, FILE *fptr_out, int count){
  char str[100];
  int i = 0;
  while(!feof(fptr_in)){
    fscanf(fptr_in, "%s %lf %lf %lf", phonearr[i].model, &phonearr[i].memory_space, &phonearr[i].screen_size, &phonearr[i].price);
    i++;
  }

  for(i = 0; i < count; i++){
    fwrite(phonearr, sizeof(phone), 1, fptr_out);
  }
}

void full_reading_mode(phone *phonearr, FILE *fptr_out, int count){
  int i;
  printf("%-25s%-20s%-25s%-10s\n", "Model", "Memory Space (GB)", "Screen Size (inches)", "Price");
  for(i = 0; i < count; i++){
    fread(phonearr, sizeof(phone), 1, fptr_out);
    printf("%-25s%-20lf%-25lf%-10lf\n", phonearr[i].model, phonearr[i].memory_space, phonearr[i].screen_size, phonearr[i].price);
  } 
}

void partial_reading_mode(phone *phonearr, FILE *fptr_out, int count){
  int a, b; //Start + end line to read
  int i;
  
  printf("Input starting line: ");
  scanf("%d", &a);
  while(a < 0 || a > count){
    printf("Number has to be >0 and < %d! Input again: ", count);
    scanf("%d", &a);
  }

  printf("Input ending line: ");
  scanf("%d", &b);
  while(b < a || b > count){
    printf("Number has to be > starting line and < %d! Input again: ", count);
    scanf("%d", &b);
  }

  printf("%-25s%-20s%-25s%-10s\n", "Model", "Memory Space (GB)", "Screen Size (inches)", "Price");
  for(i = a-1; i < b; i++){
    fread(phonearr, sizeof(phone), 1, fptr_out);
    printf("%-25s%-20lf%-25lf%-10lf\n", phonearr[i].model, phonearr[i].memory_space, phonearr[i].screen_size, phonearr[i].price);
  }
}

int menu_2(phone *phonearr, FILE* fptr_out, int count){
  __fpurge(stdin);
  char luaChon;
      
  while(luaChon != 'c'){
    printf("\n|a. Full reading mode.    |\n"
	   "|b. Partial reading mode. |\n"
	   "|c. Exit                  |\n");
    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &luaChon);
    while(luaChon < 'a' || luaChon > 'c'){
      __fpurge(stdin);
      printf("Invalid choice! Try again: ");
      scanf("%c", &luaChon);
    }
    
    switch(luaChon){
    case 'a': {
      fptr_out = fopen("PhoneDB.dat", "rb");
      if(fptr_out == NULL){
	printf("Cannot open %s.", "PhoneDB.dat");
	return 1;
      }
      
      full_reading_mode(phonearr, fptr_out, count);
      fclose(fptr_out);
      break;
    }
      
    case 'b': {
      fptr_out = fopen("PhoneDB.dat", "rb");
      if(fptr_out == NULL){
	printf("Cannot open %s.", "PhoneDB.dat");
	return 1;
      }
      
      partial_reading_mode(phonearr, fptr_out, count);
      fclose(fptr_out);
      break;
    }
    }
  }
}

void search_phone(phone *phonearr, FILE *fptr_out, int count){
  char find[MAX];
  int i;
  int mark = 0;
  printf("Input the model you want to find: ");
  scanf("%s", find);

  for(i = 0; i < count; i++){
    if(strcasecmp(find, phonearr[i].model) == 0){//So sanh khong phan biet hoa thuong
      printf("%-10s%-20lf%-25lf%-10lf\n", phonearr[i].model, phonearr[i].memory_space, phonearr[i].screen_size, phonearr[i].price);
      mark = 1;//found a phone
    }
  }
  if(mark == 0){
    printf("There aren't any phone that you need!\n");
  }

}

int main(){
  char choice;//for making menu
  phone *phonearr;
  int count; //count the number of phones in the file.txt

  FILE *fptr_in, *fptr_out;
  fptr_in = fopen("PhoneDB.txt", "r");
  if(fptr_in == NULL){
    printf("Cannot open %s.", "PhoneDB.txt");
    return 1;
  }
  fptr_out = fopen("PhoneDB.dat", "wb");
  if(fptr_out == NULL){
    printf("Cannot open %s.", "PhoneDB.dat");
    return 1;
  }

  /*---Count the number of phones in the file---*/
  count = count_phone(fptr_in);

  /*---Move the pointer to the start---*/
  rewind(fptr_in);
  
  phonearr = (phone*)malloc(count*sizeof(phone));

  while(choice != '5'){
    printf("\n|            =====MENU=====         |\n"
	   "|1. Import DB from text.            |\n"
	   "|2. Import from DB.                 |\n"
	   "|3. Print all Database.             |\n"
	   "|4. Search by phone by Phone Model  |\n"
	   "|5. Exit                            |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice < '1' || choice > '5'){
      __fpurge(stdin);
      printf("Invalid choice! Try again: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1': {
      change_into_dat(phonearr, fptr_in, fptr_out, count);
      fclose(fptr_in);
      fclose(fptr_out);
      break;
    }

    case '2': {
      menu_2(phonearr, fptr_out, count);
      break;
    }

      

    case '3': {
      fptr_out = fopen("PhoneDB.dat", "rb");
      if(fptr_out == NULL){
	printf("Cannot open %s.", "PhoneDB.dat");
	return 1;
      }
      
      full_reading_mode(phonearr, fptr_out, count);
      fclose(fptr_out);
 
      break;
    }

    case '4': {
      fptr_out = fopen("PhoneDB.dat", "rb");
      if(fptr_out == NULL){
	printf("Cannot open %s.", "PhoneDB.dat");
	return 1;
      }
      
      search_phone(phonearr, fptr_out, count);
      fclose(fptr_out);
      break;
    }
    }
  }
  free(phonearr);
  fclose(fptr_in);
  fclose(fptr_out);
}
