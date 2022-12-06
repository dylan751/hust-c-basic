#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include"stackarr(DungMangCauTruc).h"

//MAX = 100

/*---Ham so sanh do uu tien cua cac toan tu---*/
int compare(char x){
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1 ;
  if (x == '*' || x == '/' || x == '%')
    return 2;
  
}

int main(){
  char choice = '0';
  char infix[MAX], postfix[MAX];
  char x;
  StackType stack;
  int i, j = 0;
  
  while(choice != '4'){
    printf("           ===MENU===\n"
	   "|1. Enter arithmetic in infix. |\n"
	   "|2. Change to postfix form.    |\n"
	   "|3. Calculating value.         |\n"
	   "|4. Exit.                      |\n");
    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while(choice < '1' || choice > '4'){
      __fpurge(stdin);
      printf("Choice must be [1,4]! Input again: ");
      scanf("%c", &choice);
    }

    switch(choice){
    case '1': {
      printf("Input your arithmetic expression: ");
      scanf("%s", infix);

      break;
    }
      
    case '2': {
      for (i = 0; i < strlen(infix); i++){
        if(infix[i] == '('){//Neu la '(' -> cho vao stack
	  push(infix[i]-'0', &stack);
	}
	else if(infix[i] == ')'){//Neu la ')' -> lay cac toan tu trong stack ra postfix cho den khi gap dau '('
	  while((x = pop(&stack)) != '('){
	    postfix[j] = x;
	    j++;
	  }
	}
	else if(infix[i] >= '1' && infix[i] <='9'){//Neu la so -> dua vao postfix
	  postfix[j] = infix[i];
	  j++;
	}
	else{//Neu la toan tu '+', '-', '*', '/'
	  while(compare(infix[i]) <= compare(stack.storage[stack.top-1]) && !isEmpty(stack)){//So sanh do uu tien -> Neu het infix -> pop het toan tu trong stack ra
	    x = pop(&stack);
	    postfix[j] = x;
	    j++;
	  }
	  push(infix[i]-'0', &stack);
	}

	while(!isEmpty(stack)){
	  x = pop(&stack);
	  postfix[j] = x;
	  j++;
	}
	postfix[j] = '\0';
      }

      printf("Postfix expression: %s\n", postfix);
	break;
      }
      
    case '3': {
      
      break;
    }

    }
  }
}
