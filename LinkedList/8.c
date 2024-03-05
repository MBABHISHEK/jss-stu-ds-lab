#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};

typedef struct node * NODE;
void insertbypos(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);int pos,i=1;
L1: printf("Enter Position between 1 to %d : ",ph->info+1);scanf("%d",&pos);
if(pos<1 || pos>ph->info+1)
goto L1;
NODE pn=ph,tp=ph->link;
while(i<pos)
{
pn=tp;
tp=tp->link;
i++;
}
nn->link=tp;
pn->link=nn;
ph->info++;
}
void deleterear(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
NODE pn=ph,tp=ph->link;
while(tp->link!=ph)
{
pn=tp;
tp=tp->link;
}
pn->link=tp->link;
printf("Deleted %d\n",tp->info);
free(tp);ph->info--;
}
void deletefront(NODE ph)
{
if(ph->info==0)
{
printf("Empty\n");
return;
}
NODE tp=ph->link;
ph->link=tp->link;
printf("Deleted %d\n",tp->info);
free(tp);ph->info--;
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
void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->link=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert By Position\n2.Delete Rear\n3.Delete Front\n4.Search by Key\nEnter choice : ");scanf("%d",
&ch);
switch(ch)
{
case 1:insertbypos(header);display(header);break;
case 2:deleterear(header);display(header);break;
case 3:deletefront(header);display(header);break;
case 4:searchbykey(header);break;
default:exit(0);
}
}
}
