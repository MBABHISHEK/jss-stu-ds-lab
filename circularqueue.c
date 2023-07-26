#include<stdio.h>
#include<stdlib.h>
int size;
struct queue
{
int *item;
int f,r,cnt;
};
typedef struct queue QUE;
void insert(QUE *q)
{
if(q->cnt==size)
{
printf("Queue Full\nReallocating\n");
q->item=((int *)realloc(q->item,4*size*sizeof(int)));
size=size*4;
}
printf("Enter Item : ");int item;scanf("%d",&item);
q->r=((q->r+1)%size);
*(q->item+q->r)=item;
q->cnt++;
}
void delete(QUE *q)
{
if(q->cnt==0)
{
printf("EMPTY\n");
}
printf("delted %d\n",*(q->item+q->f));
q->f=((q->f+1)%size);
q->cnt--;
}
void display(QUE q)
{
if(q.cnt==0)
return;
while(q.f<=q.r)
{
printf("%d ",*(q.item+q.f));
q.f++;
}

printf("\n");
}
void main()
{
printf("Enter Size of Queue : ");scanf("%d",&size);
QUE q;
q.item=((int *)malloc(sizeof(int)*size));
q.cnt=0;q.f=0;q.r=-1;
for(;;)
{
printf("1.Insert\n2.delete\nEnter : ");int ch;scanf("%d",&ch);
switch(ch)
{
case 1:insert(&q);display(q);break;
case 2:delete(&q);display(q);break;
default:exit(0);
}
}
}
