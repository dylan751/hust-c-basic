#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>

#define LENGTH 50

void replace_char(char *str, char c1, char c2){
  if(str == NULL) return;
  
  while(*str != '\0'){
  	if(*str == c1)
  	  *str = c2;
  	  
  	++str;
  }
  printf("String after being replaced: %s\n", str);
}

int main(){
  char str[LENGTH];
  char c1, c2;

  printf("Input a string: ");
  scanf("%[^\n]s", str);

  __fpurge(stdin);
  printf("Charater you want to replace: ");
  scanf("%c", &c1);
  __fpurge(stdin);
  printf("Replace with: ");
  scanf("%c", &c2);
  
  replace_char(str, c1, c2);
  
}
