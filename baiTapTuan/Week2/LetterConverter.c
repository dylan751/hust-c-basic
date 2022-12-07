/*---Chuong trinh doc file, doi chu hoa -> thuong, doi chu thuong -> hoa roi ghi vao file khac--*/

#include<stdio.h>
#include<ctype.h>

int main(int argc, char *argv[]){
  char c;
  
  if(argc != 3){
    printf("Wrong Syntax! Should be: <fin> <fout>");
    return 1;
  }
  else{
    FILE *fptr1 = fopen(argv[1], "r");
    FILE *fptr2 = fopen(argv[2], "w");

    if(fptr1 == NULL){
      printf("Cannot open %s.\n", argv[1]);
      return 1;
    }
    else if(fptr2 == NULL){
      printf("Cannot open %s.\n", argv[2]);
      return 1;
    }
    else{
      while((c = fgetc(fptr1)) != EOF){
	if(islower(c)){//Neu c la chu cai thuong
	  c = toupper(c);//Viet hoa c
	  fputc(c, fptr2);
	}
	else{//Neu c la chu cai hoa
	  c = tolower(c);//Viet thuong c
	  fputc(c, fptr2);
	}
      }

      fclose(fptr1);
      fclose(fptr2);
   }
  }
}
