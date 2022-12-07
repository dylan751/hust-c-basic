#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
#define max 200
 
typedef struct
{
   char b[max];
}c;
int main ()
{
 char m[max];
 //m=(char*)calloc(300,sizeof(char));
 FILE*ptr,*ptr1;
 c k[max];
 int i=0,j,a;
  __fpurge(stdin);
 scanf("%s",m);
 ptr=fopen(m,"r");
 if(ptr==NULL)
 {
   printf("No such file or directory !");
   return 0;
 }
 while(!feof(ptr))
 {
   __fpurge(stdin);
   fgets(k[i].b,max,ptr);
   i++;
 }
 fclose(ptr);
 for(j=0;j<i;j++)
 {
   for(a=0;a<max;a++)
   {
       if(k[j].b[a]>=65&&k[j].b[a]<91)
       {
           k[j].b[a]+=32;
       }
       else if(k[j].b[a]>=97&&k[j].b[a]<122)
       {
           k[j].b[a]=k[j].b[a]-32;
       }
       else continue;
   }
  }
  ptr1=fopen("copy.txt","w+");
for(j=0;j<i;j++)
{
fprintf(ptr1,"%s",k[j].b);
}
fclose(ptr1);
 
}

