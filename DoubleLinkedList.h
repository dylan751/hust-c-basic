#include<stdio.h>
#include<stdlib.h>
#define CONSTANT 100
typedef struct
{
char model[CONSTANT];
   char memory[CONSTANT];
   double size;
   double price ;
}elementtype;
 
struct node
{
   elementtype element;
   struct node *prev;
   struct node *next;
};
 
typedef struct node node;
node*root,*cur,*tail,*prev;
 
 
node* make_new_node(elementtype p)// ham cap phat bo nho
{
   node*temp; // khai bao 1 nut
   temp=(node*)malloc(1*sizeof(node));
   temp->prev=NULL;
   temp->next=NULL;
   temp->element=p;
   return temp;
}
void displayNode(node*p)
{
   if(p==NULL)
   {
       printf("Loi con tro NULL\n");
       return ;
   }
   elementtype tmp=p->element;
   printf("%-25s %-7s %-14.1lf %-16.1lf \n",tmp.model,tmp.memory,tmp.size,tmp.price);
  // printf("%-20s%-30s%-20s%p\n",tmp.name,tmp.email,tmp.tel,p->next);
}
elementtype input()
{
   elementtype p;
 
   return p;
}
//void Travelling List()
//void InserttoCurrentPos(address)
 
void AddtoHead(elementtype p)
{
   node*tmp=make_new_node(p);
   if(root==NULL)
   {
       root=tmp;
       tail=root;
       cur = tmp;  
   }
   else
   {
       tmp->next=root;
       root->prev=tmp;
       tmp->prev = NULL;
       root=tmp;
       cur=root;
   }
   return ;
}
void deleteTail()
{
   node*a;
   a=tail;
   tail=tail->prev;
   tail->next=NULL;
   free(a);
   cur=tail;
}
void FindTail(node*tail)
{
   node *tmp=root;
   if(root==NULL)
   {
       printf("The list doesn't exits !");
   }
   else
   {
       tmp=root;
       while(tmp->next!=NULL)
       {
           tmp=tmp->next;
       }
       tail=tmp;
   }
   return ;
}
void append(elementtype p)
{
   node*m=make_new_node(p);
   if(tail==NULL)
   {
     root = m;
     tail=root;
   }
   else
   {
   m->prev=tail;
   tail->next=m;
   tail=m;
   cur=tail;
   }
}
void AddtoTail(elementtype p)
{
   node *tmp=make_new_node(p),*a;
   if(root==NULL)
   {
       root=tmp;
       tail=root;
   }
   else
   {
       a=root;
       while(a->next!=NULL)
       {
           a=a->next;
       }
       tmp->prev=a;
       a->next=tmp;
       tmp->next = NULL;
       cur=tmp;
       tail=tmp;
   }
   return ;
}
node* DeleteExpectedLocation(node*root,int n)
{
   node*a;
   a=root;
   int i;
   for(i=1;i<n;i++)
   {
       prev=a;
       a=a->next;
   }
   cur=a->next;
   cur->prev=prev;
   prev->next=cur;
   free(a);
   return root;
}
node* InsertExpectedLocation(int n,node*root,elementtype p)
{
   node*tmp=make_new_node(p),*a;
   a=root;
   int i;
   if(n == 0){
     AddToHead(p);
     return tmp;
   }
   
   for(i=1;i<=n;i++)
   {
       prev=a;
       a=a->next;
   }
   tmp->next=a;
   a->prev=tmp;
   prev->next=tmp;
   tmp->prev=prev;
   cur=tmp;
   return tmp;
}
void Traversingfromroot (node*root)
{
   node*p;
   p=root;
   while(p!=NULL)
   {
       displayNode(p);
       p=p->next;
   }
}
void Traversingfromtail (node*tail)
{
   node*p;
   p=tail;
   while(p!=NULL)
   {
       displayNode(p);
       p=p->prev;
   }
}
void delFirstElement()
{   if(root==NULL)
   {
       printf("Ko co gi de xoa het nha :v");
       return;
   }
   else
   {
       root=root->next;
       root->prev=NULL;
   }
}
void delCurrentElement()
{
   node*a;
   if(cur==NULL)
   {
       printf("Ko co gi de xoa het :v__");
       return;
   }
   if(cur==tail)
   {
       a=tail->prev;
       a->next=NULL;
       tail=a;
       cur=tail;
       return;
   }
   if(cur==root)
   {
       root=root->next;
       root->prev=NULL;
   }
   a=cur->prev;
   cur=cur->next;
   a->next=cur;
   cur->prev=a;
   cur=a;
  
  
}
void insertBeforeCurrent(elementtype p)
{
   node* new = make_new_node(p);
   if(root == NULL)
   {
   /*if there is no element*/
   root = new;
   cur = root;
   prev=NULL;
   }
   else if(cur == root){
     new->next = cur;
     cur->prev = new;
     root = new;
     new->prev = NULL;
     cur = new;
   }
   else{
       new->next=cur->prev->next;
       cur->prev->next = new;
       cur->prev = new;
       new->prev = cur->prev;
       cur = new;
   }
 
}
void insertAfterCurrent(elementtype p)
{
   node* new = make_new_node(p);
   if(root == NULL)
   {
   /*if there is no element*/
   root = new;
   cur = root;
   }
   else
   {
   if(cur == NULL)
   {
   return;
   }
   else
   {
   new->next = cur->next;
   cur->next = new;
   new->prev = cur;
   prev = cur; /*(neu muon de con tro prev luon dung truoc con tro cur) -> nen dung*/
   cur = cur->next;
   }
   }
}
 
void ClearData()//free list
{
   node*  to_free = root ;
   while (to_free != NULL)
   {
   root = root->next;
   free(to_free);
   to_free = root;
   }
 
}
node* reverse(node* root)
{
 node* new_root = 0;
 while (root) {
   node* next = root->next;
   root->next = new_root;
   new_root = root;
   root = next;
 }
 return new_root;
}
int CountElement()
{
   int i=1;
   node*p=root;
   if(root==NULL)
   {
       return 1;
   }
   else
   {
   while(p!=NULL)
   {
       p=p->next;
       i++;
   }
   return i;
   }
}
node* split(node*r, int n1, int n2)
{
   node *p=root,*m;
   int i=1;
   int n=CountElement();
   while(n1>n||n2>n||(n1+n2)>n||n1<0||n2<0)
   {
       printf("Enter n1 and n2 again !");
       scanf("%d %d",&n1,&n2);
   }
   while(i!=n1)
   {
       prev=p;
       p=p->next;
       i++;
   }
   r=p;
   m=r;
   i=1;
   while(i!=n2)
   {
       m=m->next;
       i++;
   }
   cur=prev->next;
   prev->next=m->next;
   m->next=NULL; // cat danh sach duoc bat dau tu r
   return r;
}
void TraversingOption (node*r)
{
   node*p;
   p=r;
   while(p!=NULL)
   {
       displayNode(p);
       p=p->next;
   }
}
