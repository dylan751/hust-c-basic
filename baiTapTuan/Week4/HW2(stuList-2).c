/*---This program will read a text file contains student informations -> input marks for each students -> print the information into file "transcript.txt"---*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define CONSTANT 100


typedef struct{
  int no;               //STT
  double number;           //MSSV
  char name[CONSTANT];  //Ten SV
  char phone[CONSTANT]; //SDT
  double mark;          //Diem
}SV;


void stu_output(FILE* fptr1, SV *stu, int stu_count){
  FILE* fptr2 = fopen("transcript.txt", "w");
  int i = 0;

  /*---Doc ghi file---*/
  while(fscanf(fptr1, "%d\t%lf\t%s\t%s", &(stu+i)->no, &(stu+i)->number, (stu+i)->name, (stu+i)->phone) != EOF){//Scan until the end of file
    printf("Input the mark of student %d: ", i+1);
    scanf("%lf", &(stu+i)->mark);
    
    while((stu+i)->mark > 10 || (stu+i)->mark < 0){//Check if the mark is valid or not
      printf("Wrong mark! Input again: ");
      scanf("%lf", &(stu+i)->mark);
    }
    i++;
  }

  /*---Input the infor into transcript.txt---*/
  fprintf(fptr2, "%-20s%-20s%-20s%-20s%-20s\n", "Num", "Stu_number", "Name", "Phone_number", "Mark");
  
  for(i = 0; i < stu_count; i++){
    fprintf(fptr2, "%-20d%-20lf%-20s%-20s%-20.2lf\n", (stu+i)->no, (stu+i)->number, (stu+i)->name, (stu+i)->phone, (stu+i)->mark);
  }
  
  fclose(fptr2);
}

void stu_add(SV* stu, int stu_count, int add){
  int i = 0;
  FILE* fptr2 = fopen("transcript.txt", "a+");//Open file for appending
  if(fptr2 == NULL){
    printf("Cannot open transcript.txt");
    return ;
  }
  
  for(i = stu_count - add; i < stu_count; i++){
    (stu+i)->no  = stu_count - add + 1;
    printf("Input student-%d's number: ", i+1);
    scanf("%lf", &(stu+i)->number);

    __fpurge(stdin);
    printf("Input student-%d's name: ", i+1);
    scanf("%s", (stu+i)->name);

    __fpurge(stdin);
    printf("Input student-%d's phone number: ", i+1);
    scanf("%s", (stu+i)->phone);

    __fpurge(stdin);
    printf("Input student-%d's mark: ", i+1);
    scanf("%lf", &(stu+i)->mark);
  }

  /*---Input the infor into transcript.txt---*/
  for(i = stu_count - add; i < stu_count; i++){
    fprintf(fptr2, "%-20d%-20lf%-20s%-20s%-20.2lf\n", (stu+i)->no, (stu+i)->number, (stu+i)->name, (stu+i)->phone, (stu+i)->mark);
  }
  
  fclose(fptr2);
}

int main(int argc, char *argv[]){
  SV* stu;
  FILE *fptr1;
  int i = 0, stu_count = 0;//count the number of the students
  int add;//The number of students you want to add
  char str[CONSTANT];
  char luaChon; //de lam Menu

  
  
  if(argc != 2){
    printf("Wrong syntax! Should be: HW2 <file_in>.");
    return 1;
  }
   else{
     fptr1 = fopen(argv[1], "r");
     if(fptr1 == NULL){
       printf("Cannot open %s.", argv[1]);
       return 1;
     }
     /*---Count the number of the students in the list---*/
     while((fgets(str, 1000, fptr1) != NULL)){//Het 1 dong -> so luong sinh vien++
       stu_count++;
     }

     /*---Return pointer to the beginning of file---*/
     fseek(fptr1, 0, SEEK_SET);
     
     /*---Cap phat bo nho dong cho mang stu---*/
     stu = (SV*)calloc(stu_count+3, sizeof(SV));
     if(stu == NULL){
       printf("Memory allocation failed!");
       return 1;
     }
	
     while(luaChon != '3'){
       __fpurge(stdin);
       printf("     =================MENU=================\n"
	      "|1. Input mark & print out the student list -> transcript.txt |\n"
	      "|2. Add more student into stulist.txt.                        |\n"
	      "|3. Exit.                                                     |\n");
     
       printf("Input your choice: ");
       scanf("%c", &luaChon);
     
       while(luaChon < '1' || luaChon > '2'){
	 __fpurge(stdin);
	 printf("Invalid! Re-input your choice: ");
	 scanf("%c", &luaChon);
       }
     
       switch(luaChon){
       case '1': {
	 stu_output(fptr1, stu, stu_count);
	 break;
       }
          
       case '2': {
	 /*---Return pointer to the beginning of file---*/
	 fseek(fptr1, 0, SEEK_SET);
	 
	 printf("Input the number of students you want to add: ");
	 scanf("%d", &add);

	 /*---Tai cap phat bo nho dong moi cho mang stu---*/
	 stu = (SV*) realloc (stu, add);
	 stu_count += add;//Update the stu_count parameter
	 
	 stu_add(stu, stu_count, add);
	 break;
       }
       }
     }
   }

  free(stu);
  fclose(fptr1);
}
