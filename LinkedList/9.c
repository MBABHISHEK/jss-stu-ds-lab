#include<stdio.h>
#include<stdlib.h>
struct node

{
int info;
struct node *LL,*RL;
};
typedef struct node * NODE;
void insertbyorder(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
NODE tp=ph->RL;
while(tp!=ph && tp->info<nn->info)
{
tp=tp->RL;
}
nn->RL=tp;
nn->LL=tp->LL;
tp->LL->RL=nn;
tp->LL=nn;
ph->info++;
}
void deleterear(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
NODE tp=ph->RL;
while(tp->RL!=ph)
{
tp=tp->RL;
}
tp->LL->RL=tp->RL;
tp->RL->LL=tp->LL;
printf("Deleted %d\n",tp->info);
free(tp);
ph->info--;
}
void deletefront(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
NODE tp=ph->RL;
tp->RL->LL=tp->LL;
ph->RL=tp->RL;
printf("Deleted %d\n",tp->info);
free(tp);
ph->info--;
}
void searchbypos(NODE ph)
{
if(ph->info==0)

{
printf("Empty\n");
return;
}
int pos,i=1;
L1: printf("Enter Position between 1 to %d : ",ph->info);scanf("%d",&pos);
if(pos<1 || pos>ph->info)
goto L1;
NODE tp=ph->RL;
while (i<pos)
{
tp=tp->RL;
i++;
}
printf("Element is %d\n",tp->info);
}
void display(NODE ph)
{
if(ph->info==0)
return;
printf("Elements are : ");
NODE tp=ph->RL;
while(tp!=ph)
{
printf("%d ",tp->info);
tp=tp->RL;
}
printf("\n");
}
void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->LL=header->RL=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert By Order\n2.Delete Rear\n3.Delete Front\n4.Search By Key\nEnter choice : ");scanf("%d",&c
h);
switch(ch)
{
case 1:insertbyorder(header);display(header);break;
case 2:deleterear(header);display(header);break;
case 3:deletefront(header);display(header);break;
case 4:searchbypos(header);break;
default:exit(0);
}
}
}
