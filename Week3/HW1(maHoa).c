/*---Chuong trinh ma hoa -> ghi ket qua ra file codedtext.txt*/
#include<stdio_ext.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
int main(int argc, char*argv[]){
  if(argc!=3){
   printf("Wrong Syntax! Should be: HW1 <file_name> <number>");
   return 0;
  }
  char*m;
  int i,size;// size la do lech cong
  int c;
  FILE*fptr1,*fptr2;
  fptr1=fopen(argv[1],"r");
  if ((fptr1 = fopen(argv[1],"r")) == NULL){
    printf("Cannot open %s \n", argv[1]);
    return 0;
  }
  fptr2=fopen("codedtext.txt","w");
  size=atof(argv[2]);
 
  while((c=fgetc(fptr1))!=EOF){
    if(c>='a'&&c<='z'){// neu c la chu thuong
      if(c+size>'z'){// neu vuot qua chu Z thi quay lai tu dau theo yc de bai
	c=c+size-'z'+'a';
      }
      else c+=size;
    }
    if(c>='A'&&c<='Z'){// neu c la chu hoa
      if(c+size>'Z'){// neu vuot qua chu Z thi quay lai tu dau theo yc de bai
	c=c+size-'Z'+'A';
      }
      else c+=size;
    }
    fputc(c,fptr2);
  }
  fclose(fptr1);
  fclose(fptr2);
}
