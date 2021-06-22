#include<stdio.h>
#include<stdlib.h>
struct Node
{

    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int size)
{
int i;
 struct Node *temp,*last;
 head=(struct Node*)malloc(sizeof(struct Node));
 head->data=A[0];
 head->next=NULL;
 last=head;
 for(i=1;i<size;i++)
 {
     temp=(struct Node*)malloc(sizeof(struct Node));
      temp->data=A[i];
      temp->next=NULL;
      last->next=temp;
      last=temp;
 }


}
int Max(struct Node *p)
{
    int max=-32768;
    while(p)
    {
       if(p->data>max)
       {
        max=p->data;
       }
       p=p->next;
    }
 return max;
}
int RMax(struct Node *p)
{
    int x=0;
    if (p==0)
       return -32768;
    x=RMax(p->next);
    if(x>p->data)
         return x;
    else 
       return p->data;
}

int main()
{
   int A[]={1,2,3,4,5,6,7,8,9,0};
  int size=sizeof(A)/sizeof(A[0]);
   create(A,size);
  printf("max element is=%d\n", Max(head));
  printf("max element is=%d\n", RMax(head));
  

    return 0;
}
