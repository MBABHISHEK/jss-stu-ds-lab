#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node * NODE;
void insertfront(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
NODE tp=ph->link;
nn->link=tp;
ph->link=nn;
ph->info++;
}
void insertrear(NODE ph)
{
NODE nn=((NODE)malloc(sizeof(struct node)));
printf("Enter the Element : ");scanf("%d",&nn->info);
NODE pn=ph,tp=ph->link;
while(tp->link!=ph)
{
tp=tp->link;
}
nn->link=tp->link;
tp->link=nn;
ph->info++;
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


void searchbypos(NODE ph) {
    if (ph->info == 0) {
        printf("Empty\n");
        return;
    }
    int pos, i = 1;
L1:
    printf("Enter Position between 1 to %d : ", ph->info);
    scanf("%d", &pos);
    if (pos < 1 || pos > ph->info)
        goto L1;
    NODE tp = ph->link;
    while (i < pos) {
        ph = tp;
        tp = tp->link;
        i++;
    }
    printf("THE ELEMENT AT THE POSITION %d is %d\n", pos, tp->info);
}
void main()
{
NODE header=((NODE)malloc(sizeof(struct node)));
header->link=header;int ch;header->info=0;
for(;;)
{
printf("\n1.Insert Front\n2.Insert Rear\n3.Delete by key\n4.Search by pos\nEnter choice : ");scanf("%d",&ch);
switch(ch)
{
case 1:insertfront(header);display(header);break;
case 2:insertrear(header);display(header);break;
case 3:deletebykey(header);display(header);break;
case 4:searchbypos(header);break;
default:exit(0);
}
}
}
