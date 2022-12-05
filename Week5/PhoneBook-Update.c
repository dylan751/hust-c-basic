#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define CONSTANT 100
typedef struct{
  char name[CONSTANT];
  char tel[CONSTANT];
  char email[CONSTANT];
}phone;

int main(){
  FILE *fptr;
  phone *phonearr;
  int i, n;
  int x, y, update;
  int irc;//dem so phan tu doc thanh cong

  fptr = fopen("phonebook.dat", "r+b");
  if(fptr == NULL){
    printf("Cannot open %s.\n", "phonebook.dat");
    return 1;
  }
  
  printf("Read from 'x' data to 'y' data! Input x, y: ");
  scanf("%d%d", &x, &y);
  while(x > y){
    printf("Invalid number! 'x' must be smaller than 'y': ");
    scanf("%d%d", &x, &y);
  }

  phonearr = (phone*)calloc((y-x+1), sizeof(phone));
  if(phonearr == NULL){
    printf("Memory allocation failed!");
    return 1;
  }
  
  /*---Move the pointer to where 'x' locates---*/
  if(fseek(fptr, (x-1)*sizeof(phone), SEEK_SET) != 0){
    printf("Fseek failed!");
    return 1;
  }
  
  irc = fread(phonearr, sizeof(phone), y-x+1, fptr);

  for(i = 0; i < y-x+1; i++){
    printf("%s-", phonearr[i].name);
    printf("%s-", phonearr[i].tel);
    printf("%s\n", phonearr[i].email);
  }
  
  // Modifying some data
  printf("Input the student's number you want to update info: ");
  scanf("%d", &update);

  __fpurge(stdin);
  printf("New name: ");
  scanf("%s", phonearr[update-1].name);

   __fpurge(stdin);
  printf("New telephone number: ");
  scanf("%s", phonearr[update-1].tel);

   __fpurge(stdin);
  printf("New email: ");
  scanf("%s", phonearr[update-1].email);
  
  fseek(fptr,1*sizeof(phone),SEEK_SET);
  
  irc = fwrite(phonearr, sizeof(phone), 2, fptr);

  printf("\n\n\n");
  for(i = 0; i < y-x+1; i++){
    printf("%s-", phonearr[i].name);
    printf("%s-", phonearr[i].tel);
    printf("%s\n", phonearr[i].email);
  }
  
  free(phonearr);
  fclose(fptr);
  
  return 1;
}
