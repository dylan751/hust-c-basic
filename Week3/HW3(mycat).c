#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define max 200

int main(int argc, char *argv[]){
  char m[max];
  FILE *fptr1;
  int c=1;
  int press;
  if(argc != 2 && argc != 3){
    printf("Wrong syntax! Should be: HW3 <file_name> or HW3 <file_name> -p\n");
    return 0;
  }
  fptr1=fopen(argv[1],"r");
  if(fptr1 == NULL){
    printf("No such file or directory !__");
    return 0;
  }
  if(argc==2){// neu chi truyen vao ten file
    while((fgets(m,max,fptr1))!=NULL){
      printf("%s",m);
    }
  }
  if(argc==3&&strcmp(argv[2],"-p")==0){// neu truyen ten file va lenh ”-p”
    while((fgets(m, max, fptr1))!= NULL){
      if(c%30 == 0){// neu so thu tu dong doc tu file ma chia het cho 30 thi yeu cau enter de tiep tuc 
	printf("Press Enter to continue.");
	press = getchar();
	while(press != '\n'){
	  press = getchar();
	}
	system("clear");// xoa toan bo man hinh moi khi duoc 25 dong
      }
      printf("%s",m);
      c++;
    }
  }
  
  fclose(fptr1);
}
