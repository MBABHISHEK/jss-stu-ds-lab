#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *LL,*RL;
};
typedef struct node *NODE;
NODE construct(NODE r)
{
int ch;
for(;;)
{
printf("Enter 1 for Insertion and 0 to STOP :");scanf("%d",&ch);
if(ch==0)
break;
NODE nn=((NODE)malloc(sizeof(struct node)));nn->RL=nn->LL=NULL;
printf("Enter Info : ");scanf("%d",&nn->info);
if(r==NULL)
return nn;
NODE tp=r,pn=NULL;
while(tp!=NULL)
{
pn=tp;
if(nn->info<tp->info)
tp=tp->LL;
else
tp=tp->RL;
}
if(nn->info<pn->info)
pn->LL=nn;
else
pn->RL=nn;
}
return r;
}
void inorder(NODE r)
{
if(r==NULL)
return;
inorder(r->LL);
printf("%d ",r->info);
inorder(r->RL);
}
void postorder(NODE r)
{
if(r==NULL)

return;
postorder(r->LL);
postorder(r->RL);
printf("%d ",r->info);
}
void preorder(NODE r)
{
if(r==NULL)
return;
printf("%d ",r->info);
preorder(r->LL);
preorder(r->RL);
}
int count(NODE r)
{
if(r==NULL)
return 0;
int cnt=0;cnt++;
cnt=cnt+count(r->LL)+count(r->RL);
return cnt;
}
int Max(int a,int b)
{
if(a>b)
return a;
else if(a<b)
return b;
else
return a;
}
int height(NODE r)
{
if(r==NULL)
return -1;
return(1+Max(height(r->RL),height(r->LL)));
}
void searchbykey(NODE r)
{
if(r==NULL)
{
printf("Tree Empty\n");
return;
}
printf("Enter The Key : ");int key;scanf("%d",&key);
if(r->info==key)
{
printf("Element Found and its the Root of The Tree\n");
return;
}
NODE tp=r,pn=NULL;
while(tp!=NULL)
{
pn=tp;
if(key<tp->info)
tp=tp->LL;

else
tp=tp->RL;
if(tp==NULL)//if not found tp will be NULL
{
printf("Element not Found\n");
return;
}
if(tp->info==key)
{
printf("Element Found and Parent is %d\n",pn->info);
return;
}
}
}

void main()
{
NODE root=NULL;
int ch;
for(;;)

{
printf("1.Tree Construction\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Search by Key\n6.Total Nodes\n7.Height\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:root=construct(root);break;
case 2:printf("Inorder Traversal is : ");inorder(root);printf("\n");break;
case 3:printf("Preorder Traversal is : ");preorder(root);printf("\n");break;
case 4:printf("Postorder Traversal is : ");postorder(root);printf("\n");break;
case 5:searchbykey(root);break;
case 6:printf("Total Nodes is : %d\n",count(root));break;
case 7:printf("Height is : %d\n",height(root));break;
}
}
}
