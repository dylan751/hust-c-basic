/*---This program will read a text file contains student informations -> input marks for each students -> print the information into file "transcript.txt"---*/
#include<stdio.h>
#define CONSTANT 100
typedef struct{
  int no;               //STT
  int number;           //MSSV
  char name[CONSTANT];  //Ten SV
  char phone[CONSTANT]; //SDT
  double mark;          //Diem
}SV;

int main(int argc, char *argv[]){
  SV stu[CONSTANT];
  int i = 0, count = 0;//count the number of the students
  if(argc != 2){
    printf("Wrong syntax! Should be: HW2 <file_in>.");
    return 1;
  }
  else{
    FILE *fptr1 = fopen(argv[1], "r");
    FILE *fptr2 = fopen("transcript.txt", "w");

    if(fptr1 == NULL){
      printf("Cannot open %s.", argv[1]);
      return 1;
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.", "transcript.txt");
      return 1;
    }
    else{
      while(fscanf(fptr1, "%d\t%d\t%s\t%s", &stu[i].no, &stu[i].number, stu[i].name, stu[i].phone) != EOF){//Duyet den cuoi file
	printf("Input the mark of student %d: ", i+1);
	scanf("%lf", &stu[i].mark);
	
	while(stu[i].mark > 10 || stu[i].mark < 0){//Check if the mark is valid or not
	  printf("Wrong mark! Input again: ");
	  scanf("%lf", &stu[i].mark);
	}
	i++;
	count++;
      }

      /*---Input the infor into transcript.txt---*/
      fprintf(fptr2, "%-20s%-20s%-20s%-20s%-20s\n", "Num", "Stu_number", "Name", "Phone_number", "Mark");
      for(i = 0; i < count; i++){
	fprintf(fptr2, "%-20d%-20d%-20s%-20s%-20.2lf\n", stu[i].no, stu[i].number, stu[i].name, stu[i].phone, stu[i].mark);
      }
    }

    fclose(fptr1);
    fclose(fptr2);
  }
}
