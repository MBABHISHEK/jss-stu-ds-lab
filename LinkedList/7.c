#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;

struct node *LL,*RL;
};
typedef struct node * NODE;
void insertfront(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
nn->RL=ph->RL;
nn->LL=ph;
ph->RL=nn;
if(ph->info==0)
{
ph->LL=nn;
}
ph->info++;
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
void searchbykey(NODE ph)
{
if(ph->info==0)
return;
int key;NODE tp=ph->RL;
printf("Enter the Element : ");scanf("%d",&key);
while(tp!=ph)
{
if(tp->info==key)
{
printf("Element Found %d\n",tp->info);
return;
}
tp=tp->RL;
}
if(tp==ph)
{
printf("Element Not Found\n");
}
}
void insertrear(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
nn->LL=ph->LL;

nn->RL=ph;
ph->LL->RL=nn;
ph->LL=nn;
ph->info++;
}
void deletebypos(NODE ph)
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
NODE tp=ph->RL,pn=ph;
while(i<pos)
{
pn=tp;
tp=tp->RL;
i++;
}
pn->RL=tp->RL;
tp->RL->LL=pn;
printf("Deleted %d\n",tp->info);
free(tp);
ph->info--;
}
void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->LL=header->RL=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert Front\n2.Insert Rear\n3.Delete By Position\n4.Search By Key\nEnter choice : ");scanf("%d",
&ch);
switch(ch)
{
case 1:insertfront(header);display(header);break;
case 2:insertrear(header);display(header);break;
case 3:deletebypos(header);display(header);break;
case 4:searchbykey(header);break;
default:exit(0);
}
}
}
