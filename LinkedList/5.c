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
void deletebykey(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
int key;
printf("Enter key Elment : ");scanf("%d",&key);
NODE tp=ph->RL;
while(tp!=ph)
{
if(tp->info==key)
{
tp->LL->RL=tp->RL;
tp->RL->LL=tp->LL;
printf("Deleted %d\n",tp->info);
free(tp);
ph->info--;
return ;
}
tp=tp->RL;
}

}
void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->LL=header->RL=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert By Order\n2.Delete By Key\n3.Search By Position\nEnter choice : ");scanf("%d",&ch);
switch(ch)
{
case 1:insertbyorder(header);display(header);break;
case 2:deletebykey(header);display(header);break;
case 3:searchbypos(header);break;
default:exit(0);
}
}
}
