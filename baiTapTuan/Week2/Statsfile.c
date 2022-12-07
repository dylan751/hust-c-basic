/*---Doc file1 -> dem so lan tung chu cai xuat hien -> ghi ket qua vao file sourcestats.txt---*/

#include<stdio.h>
#include<string.h>
#define CONST 50
#define ALPHABET_LENGTH 26
int main(int argc, char *argv[]){
  int word_count[ALPHABET_LENGTH] = {0};
  char c;
  int i;
  char stat[CONST];

  if(argc != 2){
    printf("Wrong Syntax! Should be: <string>.");
    return 1;
  }
  else{
    FILE *fptr1 = fopen(argv[1], "r");
    FILE *fptr2 = fopen("sourcestats.txt", "w");
    if(fptr1 == NULL){
      printf("Cannot open %s", argv[1]);
      return 1;
    }
    else if(fptr2 == NULL){
      printf("Cannot open sourcestats.txt");
    }
    else{
      while((c = fgetc(fptr1)) != EOF){
	if(c <= 'z' && c >= 'a'){//chu thuong
	  word_count[c-'a']++;
	}
	else if(c <= 'Z' && c >= 'A'){//chu hoa
	  word_count[c-'A']++;
	}
      }

      for(i = 0; i <= ALPHABET_LENGTH; i++){
	if(word_count[i] > 0){
	  fprintf(fptr2, "Letter '%c' appears %d times.\n",i+'a', word_count[i]); 
	}
      }

      fclose(fptr1);
      fclose(fptr2);
    }
  }

  return 1;
  
}
