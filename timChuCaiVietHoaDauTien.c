/*Chua lam truong hop neu khong co chu nao viet hoa*/

#include<string.h>
#include<stdio.h>
#define max 200
char capletter(char *m, char k, int i){
  k=*(m+i);
  if(k<90&&k>63){//Neu k viet in hoa
    return k;
  }
  else{
    i++;
    return capletter(m,k,i);
  }
  
  
}

int main(){
   char a[max], k;
   int i = 0;
   printf("Enter a string: ");
   fgets(a,max,stdin);
   k= capletter(a,k,i);
   printf("First capital letter in the string: %c\n",k);
}
