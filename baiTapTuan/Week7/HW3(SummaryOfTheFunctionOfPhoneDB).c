#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include"GenSLL.h"
#define CONSTANT 100
 
elementtype input_phone()
{
   elementtype p;
   printf("Input Model :__");
   scanf("%s",p.model);
    printf("Phone memory :__");
   scanf("%s", p.memory);
    printf("Screen size:__");
   scanf("%lf", &p.size);
   while(p.size < 0)
   {
   printf("Error! the size must be > 0! Input again: ");
   scanf("%lf", &p.size);
   }
 
   printf("Phone price:__");
   scanf("%lf", &p.price);
   while(p.price < 0)
   {
   printf("Error! the price must be > 0! Input again: ");
   scanf("%lf", &p.price);
   }
    return p;
}
 
void so1(FILE*input1)
{
    elementtype *m,p;
 
           while((int*)fread(m,sizeof(elementtype),1,input1)!=NULL)
           {
               p=*m;
               AddtoTail(p);
           }
          
}
 
void search()
{
   node*p;
   char*k=(char*)malloc(100*sizeof(char));
   int i=0;
   printf("Enter the phone model u wanna find :");
   scanf("%s",k);
   p=root;
   while(p!=NULL)
   {
       if(strcasecmp(p->element.model,k)==0)
       {
           displayNode(p);
           i++;
       }
       p=p->next;
   }
   if(i==0)
   printf("Can't find the phone model u need !__");
   free(k);
}
 
void exporttodat()
{
   FILE*output=fopen("PhoneDB.dat","wb");
   node*p;
   p=root;
   elementtype*m;
   while(p!=NULL)
   {
       strcpy(m->model,p->element.model);
       strcpy(m->memory,p->element.memory);
       m->price=p->element.price;
       m->size=p->element.size;
       fwrite(m,sizeof(elementtype),1,output);
       p=p->next;
   }
 
   fclose(output);
}
 
void ManualInsertion()
{
   int choice;
   elementtype p;
   while(choice != 3)
   {
   printf("                ---Menu---\n"
      "|1. Input one new model BEFORE current node.|\n"
      "|2. Input one new model AFTER current node .|\n"
      "|3. Exit.                                   |\n");
   printf("Input your choice: ");
   scanf("%d", &choice);
   switch(choice)
   {
       case 1 :
       {
       p=input_phone();
       insertBeforeCurrent(p);
       break;
       }
       case 2 :
       {
       p=input_phone();
       insertAfterCurrent(p);
       break;
       }
 
   }
   }
}
int main()
{
   FILE*input1,*output;
   node*r;
   input1=fopen("PhoneDB.dat","rb");
   if(input==NULL)
   {
       printf("No such file or directory !");
       return 0;
   }
   int n1,n2;//dung cho menu 10
   int i;
   int x;
   int m,n=0;
   elementtype p;
   while(m!=12)
   {
       printf("\nMenu\n1.Import Database from .dat file.\n2.Print all Database.\n3.Manual Insertion.\n4.InsertAtPosition.\n5.DeleteAtPosition.\n6.DeleteAtCurrent.\n7.DeleteAtFirst.\n8.Search for Phone Model and Update.\n9.Divide and Extract.\n10.Reverse list.\n11.SaveToFile.\n12.Quit(Free)\n");
       scanf("%d",&m);
       switch(m)
       {
           case 1 :
           if(n==0)
           {
               so1(input1);
               n++;
           }
           else
           {
               rewind(input1);
               ClearData();
               so1(input1);
           }
           break;
           case 2 :
           Traversing();
           break;
           case 3 :
           ManualInsertion();
           break;
           case 4 :
           printf("Enter the position u wanna Insert ___");
           scanf("%d",&x);
           p=input_phone();
           InsertExpectedLocation(x,root,p);
           break;
           case 5 :
           printf("Enter the position u wanna Delete ___");
           scanf("%d",&x);
           DeleteExpectedLocation(root,x);
           break;
           case 6 :
           delCurrentElement();
           break;
           case 7 :
           delFirstElement();
           break;
           case 8 :
           search();
           break;
           case 9 :
           printf("Enter the starting point and numbers of elements u want u want____");
           scanf("%d %d",&n1,&n2);
           r=split(r,n1,n2);
           printf("The splitted list 1 is :\n");
           TraversingOption(r);
           printf("The splitted list 2 is :\n");
           Traversing();
           break;
           case 10 :
           root=reverse(root);
           break;
           case 11 :
           exporttodat();
           break;
           case 12 :
           printf("Goodbye !");
           ClearData();
           break;
          
       }
   }
   fclose(input1);
}

