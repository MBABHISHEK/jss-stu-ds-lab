
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
   int * item;
   int f,r,count,size;
};


typedef struct Queue * QUE;

void insertfront1(QUE q)
{
    int item;
  if(q->r==-1)
  {
    printf ("ENTERTHE DATA\n");
    scanf ("%d",&item);
    q->r++;
    *(q->item+q->r) =item;
    q->count++;
  }
  else if (q->f!=0)
  {
     printf  ("ENTER THE DATA\n");
    scanf ("%d",&item);
    q->f--;
    *(q->item+q->f) = item;
    q->count++;
  }
  else
   printf ("THE FRONT INSERTION IS NOT POSSIBLE TRY REAR INSERTION \n");

}

void insertrear(QUE q)
{ 
  if(q->r==q->size-1)
  {
    if(q->count==q->size)
      {
          q->size*=2;//q->size=q->size*2;
          q->item = (int*)realloc(q->item,sizeof(int)*q->size);
          printf("THE MEMORY REALLOCATED\n");
           if(q->item==NULL)
          {
          printf("THE MEMORY IF FULL\n");
          return;
          }
      }
      else 
      {
        printf("THE REAR INSERTION IS NOT POSSIBLE TRY FRONT INSERTION\n");
        return;
      }
  }
  int item;
    printf  ("ENTER THE DATA\n");
    scanf ("%d",&item);
    q->r++;
    *(q->item+q->r) = item;
    q->count++;


}


void display2(QUE q)
{
   if(q->f>q->r)
   {
     printf("THE QUEUE IS EMPTY\n");
     return;
   }
  int  i=q->f;
   while(i<=q->r)
   {
     printf("%d ",*(q->item+i));
     i++;
   }

   printf("\n");
}

void deleterear(QUE q)
{
    if(q->f>q->r)
    {
      printf("THE QUEUE IS EMPTY\n");
      return;
    }
    printf("THE ELEMENT DELTED IS %d\n",*(q->item+q->r));
    q->r--;
    q->count--;

    if(q->count==0)
    {
      q->f=0;
      q->r=-1;
    }
}
void deletefront(QUE q)
{
    if(q->f>q->r)
    {
      printf("THE QUEUE IS EMPTY\n");
      return;
    }
    printf("THE ELEMENT DELTED IS %d\n",*(q->item+q->f));
    q->f++;
    q->count--;

    if(q->count==0)
    {
      q->f=0;
      q->r=-1;
    }
}
void main()
{
   printf(" ENTER THE SIZE\n");
   struct Queue q;
   q.r=-1;
   q.count=0;
   q.f=0;
   scanf("%d",&q.size);
   q.item=(int *)malloc(q.size*sizeof(int));
   int ch;
   for(;;)
   {
    printf("ENTER THE CHOICE \n1.TO INSERTFRONT\n2.TO INSERTREAR\n3.TO DELETEFRONT\n4.TO DELETEREAR\n");
    scanf("%d",&ch);
    switch (ch)
    {
        printf("hai");
    case 1:insertfront1(&q);display2(&q); break;
    case 2:insertrear(&q);display2(&q); break;
    case 3:deletefront(&q);display2(&q);break;
    case 4:deleterear(&q);display2(&q);break;
    default:exit(0);
        break;
    }

   }
}
