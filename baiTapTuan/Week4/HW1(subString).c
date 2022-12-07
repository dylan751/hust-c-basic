#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* subStr(char* s1, int offset, int number){
  char* subStr;
  subStr = (char*)calloc(200, sizeof(char));
 
  strcpy(subStr, s1+offset);
  subStr[number] = '\0';

  return subStr;
}

int main(){
  char* str;
  int x, n;
  
  str = (char*)calloc(200, sizeof(char));
  printf("Input a string: ");
  scanf("%[^\n]s", str);

  printf("Input a number declaring where the subString starts: ");
  scanf("%d", &x);
  while(x < 0 || x > strlen(str)){
    printf("Invalid offset! Input a number that >0 and < string's length: ");
    scanf("%d", &x);
  }
  
  printf("Input the length of the subString: ");
  scanf("%d", &n);

  printf("SubStr: %s\n", subStr(str, x, n));
}
