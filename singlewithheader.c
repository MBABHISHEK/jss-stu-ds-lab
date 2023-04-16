#include<stdio.h>
#include<stdlib.h>

 struct NODE{

    int info;
    struct NODE* link;

 };
 

 typedef struct NODE NODE;
 typedef struct NODE* LINK;

  LINK createnode();
  void display(LINK);
 // LINK insertfront( LINK );
  // LINK insertrear( LINK );
   //LINK deletefront(LINK );
  //LINK deleterear(LINK);
  void insertbypos(LINK );
  void deletebypos(LINK );
  //LINK serachbykey(LINK );
  void insertbyorder(LINK );
  void deletebykey(LINK);


 void main()
 {
   LINK head;
   head=createnode();
   head->info=0;
   head->link=head;
   insertbyorder(head);
   display(head);
   insertbyorder(head);
   display(head);
   insertbyorder(head);
   display(head);
   insertbypos(head);
   display(head);
   deletebypos(head);
   display(head);
   deletebykey(head);
   display(head);


 }

  void display(LINK ph)
{ LINK tp=ph->link;
   if(ph==ph->link)
   {
   printf("THE LIST IS EMPTY\n");
   return;
   }
  while(tp!=ph)
  {
      printf("THE ELEMENT IS %d\n",tp->info);
      tp=tp->link;
  }
  

}


  void insertbypos(LINK ph)
{
   LINK tp=ph,nn;
   int pos,count=1;

    l1 :printf("ENTER THE POSITION BETWEEN 1 AND %d\n",ph->info+1);
    scanf("%d",&pos);
    if(pos<1||pos>ph->info+1)
    goto l1;
    nn=(LINK)malloc(sizeof(NODE));
    printf("ENTER THE DATA\n");
    scanf("%d",&nn->info);
    ph->info++;


    while(pos!=count)
   {
      tp=tp->link;
      count++;
   }

   nn->link=tp->link;
   tp->link=nn;
}
  void deletebypos(LINK ph)
{
   LINK tp,nn;
   int count=1,pos;
   tp=ph;


   if(ph==ph->link)
   {
     printf("THE ARRAY IS EMPTY\n");
     return ;
   }

    l1: printf("ENTER THE ELEMENTS BETWEEN THE 1 AND %d\n",ph->info);
       scanf("%d",&pos);

     if(pos<1||pos>ph->info)
     goto l1;

       while(pos!=count)
     {
        tp=tp->link;
        count++;
     }
    nn=tp->link;
    printf("THE ELEMENT DELETED IS %d\n",nn->info);
    ph->info--;
    tp->link=nn->link;
    free(nn);
}

void reverse(LINK ph)
{
  LINK tp=ph->link;
  LINK pn,sn=ph;

   while(tp!=ph)
   { 
     pn=tp;
     tp=tp->link;
     pn->link=sn;
     sn=pn;
   }
   ph->link=sn;

}

void insertbyorder(LINK ph)
{
  LINK pn=ph,tp=ph->link,nn;
    nn=(LINK)malloc(sizeof(NODE));
    printf("ENTER THE DATA\n");
    scanf("%d",&nn->info);
    ph->info++;

    while (tp!=ph&&tp->info<nn->info)
    {
        pn=tp;
        tp=tp->link;
    }
    nn->link=tp;
    pn->link=nn;
}

void deletebykey(LINK ph)
{

    LINK tp=ph,pn=ph->link;
   int key;

   if(ph==ph->link)
   {
      printf("THE LIST IS EMPTY\n");
      return ;
   }

   printf("ENTER THE ELEMENT \n");
   scanf("%d",&key);

   while(tp!=ph&&tp->info!=key)
   {
    tp=tp->link;
    pn=pn->link;
   }
   if(tp==ph)
   {
    printf("THE ELEMENT IS NOT PRESENT\n");
   }
   else
   {
     pn->link=tp->link;
      printf("THE ELEMENT DELETED IS %d\n",tp->info);
    ph->info--;
    free(tp);


   }
}





LINK createnode()
{ LINK nn;
   nn=(LINK)malloc(sizeof(NODE));
   if(nn==NULL) 
   {
    printf("memory full\n");
    exit(1);
   }
   return nn;   
} 