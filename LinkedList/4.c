#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node * NODE;
void insertbyorder(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
NODE tp=ph->link,pn=ph;
while(tp!=ph && tp->info<nn->info)
{

pn=tp;
tp=tp->link;
}
pn->link=nn;
nn->link=tp;
ph->info++;
}
void display(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
printf("Element are : ");
NODE tp=ph->link;
while(tp!=ph)
{
printf("%d ",tp->info);
tp=tp->link;
}
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
NODE tp=ph->link,pn=ph;
while(i<pos)
{
pn=tp;
tp=tp->link;
i++;
}
pn->link=tp->link;
printf("Deleted %d\n",tp->info);
free(tp);
ph->info--;
}
void searchbykey(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
int key;NODE tp=ph->link;

printf("Enter the Element : ");scanf("%d",&key);
while(tp!=ph)
{
if(tp->info==key)
{
printf("Element Found %d\n",tp->info);
return;
}
tp=tp->link;
}
if(tp==ph)
{
printf("Element Not Found\n");
}
}
void deletebykey(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}

int key;NODE tp=ph->link,pn=ph;
printf("Enter the Element : ");scanf("%d",&key);
ph->info--;
while(tp!=ph)
{
if(tp->info==key)
{
pn->link=tp->link;
printf("Deleted %d\n",tp->info);
free(tp);return;
}
pn=tp;
tp=tp->link;
}
}


void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->link=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert By Order\n2.Delete By Position\n3.Search by Key\n4.Delete By Key\nEnter choice : ");scanf("%d",&ch);
switch(ch)
{
case 1:insertbyorder(header);display(header);break;
case 2:deletebypos(header);display(header);break;
case 3:searchbykey(header);break;
case 4:deletebykey(header);display(header);break;
default:exit(0);
}
}
}
