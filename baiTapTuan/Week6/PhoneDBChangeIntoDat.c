#include<stdio.h>
#include<stdio_ext.h>
#define CONSTANT 100
typedef struct{
  char model[CONSTANT];
  double memory_space;
  double screen_size;
  double price;
}phone;

int main(){
  FILE *fptr;
  phone phonearr[CONSTANT];
  int i, n;
  int irc;//dem so phan tu doc thanh cong

  printf("How many contact do you want to enter (<20): ");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    __fpurge(stdin);
    printf("Model: ");            scanf("%[^\n]s", phonearr[i].model);
    __fpurge(stdin);
    printf("Memory space: ");     scanf("%lf", &phonearr[i].memory_space);
    __fpurge(stdin);
    printf("Screen size: ");      scanf("%lf", &phonearr[i].screen_size);

    printf("Price: ");            scanf("%lf", &phonearr[i].price);
  }

  if((fptr = fopen("PhoneDB.dat", "w+b")) == NULL){
    printf("Cannot open %s.\n", "PhoneDB.dat");
    return 1;
  }

  // write the entire array into the file
  irc = fwrite(phonearr, sizeof(phone), n, fptr);
  printf("fwrite return code = %d\n", irc);
  fclose(fptr);

  // read from this file to array again
  if((fptr = fopen("PhoneDB.dat", "rb")) == NULL){
    printf("Cannot open %s\n.", "PhoneDB.dat");
    return 1;
  }

  irc = fread(phonearr, sizeof(phone), n, fptr);
  printf("fread return code %d\n", irc);
  for(i = 0; i < n; i++){
    printf("%s-", phonearr[i].model);
    printf("%.2lf-", phonearr[i].memory_space);
    printf("%.2lf-", phonearr[i].screen_size);
    printf("%.2lf\n", phonearr[i].price);
  }
  fclose(fptr);
  return 1;
}
