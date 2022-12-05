#include<stdio.h>
#include<string.h>
#define CONSTANT 100

typedef struct{
  int line;
  int page;
}location;

int main(int argc, char* argv[]){
  char* tu_khoa = argv[1];
  location mark;//Vi tri
  mark.line = 1;
  mark.page = 1;
   if(argc != 2){
    printf("Wrong Syntax! Should be: <string>");
    return 1;
    }
   else{
    char file_name[CONSTANT] = "tuDien.txt";
    char str[CONSTANT];
    char c;
    
    FILE* fptr = fopen(file_name, "r");
    if(fptr == NULL){
      printf("Cannot open %s.", file_name);
      return 1;
    }
    else{
      while((c = fgetc(fptr)) != EOF){
	fgets(str, 99, fptr);
	fprintf(stdout, "%s", str);
	int n = 0;
	int m = 0;
        if(str[n] == tu_khoa[m]){//Neu ky tu dau tien la giong nhau
	  //tiep tuc tim kiem
	  while(str[n] == tu_khoa[m]){
	    n++;
	    m++;
	  }
	  //Neu day ky tu nay co do dai bang chuoi tim kiem
	  if(m == strlen(tu_khoa) && (str[n] == ' ' || str[n] == '\0')){
	    //Chuc mung ban da tim ra chuoi can tim
	    printf("Page: %d, line: %d\n", mark.page, mark.line);
	  }
	}
	else{//Neu ky tu dau tien khong giong nhau
	  while(str[n] != ' '){//bo qua, tiep tuc tim kiem tu tiep theo
	    n++;
	    if(str[n] == '\0'){
	      mark.line++;
	      if(mark.line > 25){
		mark.page++;
	      }
	      break;
	    }
	  }
	}

	n++;
	m = 0;//reset bien dem
      }
    }
  }
}
