#include<stdio.h>//cai nay thi khoi giai thich tai bai d nao cx dung r nha :v
#include<string.h>// thu vien de dung cac ham lien quan den xau ki tu, nhu la strcmp, strcat,vv
#include<stdlib.h>
#include<time.h>// su dung thu vien nay de co the su dung ham srand, random theo thoi gian
int main ()
{
   char article[5][6]={"the ","a ","one ","some ","any "};
   char noun[5][6]={"boy ","girl ","dog ","town ","girl "}; // chu ngu
   char verb[5][9]={"drove ","jumped ","ran ","walked ","skipped "}; // dong tu
   char preposition[5][7]={"to ","from ","over ","under ","on "};  // gioi tu
   char sentence[50]; // khai bao mang cau hoi
   int a,b,c,d,e,f,i;
   srand(time(NULL));// cai nay va ham rand() la de random so ngau nhien
   for(i=0;i<10;i++)// vi de bai yeu cau random 10 cau, nen phai dung if ^^
   {
   a=rand() % 5;//min+rand()%(max+1-min) - random cac so tu 1 den 10
   b=rand() % 5;
   c=rand() % 5;
   d=rand() % 5;
   e=rand() % 5;
   f=rand() % 5;
  
   strcpy(sentence,article[a]); // copy mang cau hoi voi article
   strcat(sentence,noun[b]); // noi cac thanh phan cua cau theo thu tu vao mang
   strcat(sentence,verb[c]);
   strcat(sentence,preposition[d]);
   strcat(sentence,article[e]);
   strcat(sentence,noun[f]);
   strcat(sentence,".");// them dau . vao cuoi cau
   sentence[0]-=32;// viet hoa chu cai dau tien trong cau bang cach - di 32. neu m ko hieu thi search bang ma ASCII la ra
   printf("%s\n",sentence); // in ra cau vua duoc tao thanh va sau do quay lai tiep tuc vong lap for .
   }
}
