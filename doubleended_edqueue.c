#include<stdio.h>
#include<stdlib.h>
int size;
struct queue
{
int *item;
int f,r;
};
typedef struct queue QUE;
void insertrear(QUE *q)
{
printf("Enter Item : ");int item;scanf("%d",&item);
if(q->r==size-1)
{
printf("Reallocating\n");
q->item=((int *)realloc(q->item,4*size*sizeof(int)));
size=size*4;
}
q->r++;
*(q->item+q->r)=item;
}
void insertfront(QUE *q)
{
if(q->f==0 && q->r!=-1)
{
printf("Front Insertion not possible\n");
return;
}
printf("Enter Item : ");int item;scanf("%d",&item);
if(q->f==0 && q->r==-1)
{
q->r++;
*(q->item+q->r)=item;
return;

}
q->f--;
*(q->item+q->f)=item;
}
void deletefront(QUE *q)
{
if(q->f>q->r)
{
printf("Empty\n");
return;
}
printf("delted %d\n",*(q->item+q->f));
q->f++;
if(q->f>q->r)
{
q->f=0;q->r=-1;
}
}
void deleterear(QUE *q)
{
if(q->f>q->r)
{
printf("Empty\n");
return;
}
printf("delted %d\n",*(q->item+q->r));
q->r--;
if(q->f>q->r)
{
q->f=0;q->r=-1;
}
}
void display(QUE q)
{
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
q.f=0;q.r=-1;
for(;;)
{
printf("1.Insert Rear\n2.Delete Front\n3.Insert Front\n4.Delete Rear\nEnter : ");int ch;scanf("%d",&ch);
switch(ch)
{
case 1:insertrear(&q);display(q);break;
case 2:deletefront(&q);display(q);break;

case 3:insertfront(&q);display(q);break;
case 4:deleterear(&q);display(q);break;
default:exit(0);
}
}
}
