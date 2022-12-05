#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>// thu vien nay chi trong ubuntu moi co
#include<stdlib.h>
#define max 100
#define min 20
typedef struct name
{
   char fullname[max];// ten day du nhap tu ban phim
   char name[min];// ten sau khi duoc tach
}a;
char * timten( char* hoten)// ham tach ten khoi ho ten duoc nhap vao
{
int i;
i = strlen(hoten)-1; // tim ki tu trang cuoi cung trong xau
while (i >= 0 && hoten[i] != ' ')
i--; // giam i den khi tim dc ki tu trang cuoi cung
return hoten + i + 1;//  ham tra ve ten
}
 
int main()
{
   a k[max],h;
   int dem[max],dem1[max];
   int i,n,j;
   int max1;
   printf("Enter the number of students :__");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("Name of student %d : __",i+1);
       __fpurge(stdin);
       fgets(k[i].fullname,max,stdin);
      strcpy(k[i].name,timten(k[i].fullname));
      dem[i]=1; dem1[i]=0; //dem la bien dem so lan xuat hien cua 1 ten , dem1 la bien dung de phan biet ten da xuat hien va chua xuat hien
      //copy ten sau khi tim duoc vao bien "ten"
   }
  
   for(i=n-1;i>=0;i--)// thuat toan sap xep dung den phat dien ca ki truoc ne, ko nho thi xem lai dong file cua t
   {
  
       for(j=0;j<i;j++)
       {
           if(strcasecmp(k[j].name,k[j+1].name)>0)// neu so sanh ten j ma lon hon ten j+1 thi thuc hien thuat toan doi vi tri
           {
           h=k[j];
           k[j]=k[j+1];
           k[j+1]=h;
           }
       }
   }
  
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
       if(strcasecmp(k[i].name,k[j].name)==0&&dem1[i]==0)
       {
           dem[i]++;
           dem1[j]++;
       }
       }
   }
   max1=dem[0];
   for(i=0;i<n;i++)// in danh sach sau khi thay doi dung thu tu ra man hinh va tim ten sinh vien xuat hien nhieu nhat
   {
       if(dem[i]>max1)
       max1=dem[i];
       printf("%s\n",k[i].name);
   }
   for(i=0;i<n;i++)// in ra man hinh ten sinh vien xuat hien nhieu nhat
   {
       if(dem[i]==max1)
       printf("ten hoc sinh xuat hien nhieu nhat: %s (%d lan)\n ",k[i].name,dem[i]);
   }
}
