#include<stdio.h>
#include<stdlib.h>

struct Queue
{
   int * item;
   int f,r,count,size;
};


typedef struct Queue QUE;


void insertcircular(QUE *q)
{
  if(q->count==q->size-1)
  {
    q->size*=2;//q->size=q->size*2;
    q->item = (int*)realloc(sizeof(int)*q->size);
    if(q->item==NULL)
    {
        printf("THE MEMORY IF FULL\n");
        return;
    }
  }
   int item;
   printf("ENTER THE DATA\n");
   scanf("%d",&item);
   q->r=(q->r+1)%q->size;
   *(q->item+q->r)=item;
   q->count++;
}

void deletecircular(QUE q)
{
  if(q->count==0)
  {
    printf("THE QUEUE IS EMPTY\n");
    return;
  }
  printf("THE ELEMENT DELETED IS %d\n",*(q->item+q->f));
  q->f=(q->f+1)%q->size;
  q->count--;
}

void display(QUE q)
{
  if(q->count==0)
  {
    printf("THE QUEUE IS EMPTY\n");
    return;
  }
  printf("THE ELEMENT OF THE QUEUE ARES\n");

  int i=q->f,j;
  j=0;
  while(j<=q->count)
  {
     printf("%d ",*(q->item+i));
     i=(i+1)%q->size;

  }
  printf("\n");
}


void circular()
{
 struct queue q;
 q.count=0;
 q.f=0;
 q.r=-1;
  printf("ENTER THE SIZE OF THE QUEUE\n");
  scanf("%d",&q.size);

  q->item=(int *)malloc(q.size*sizeof(int));
  if(q->item==NULL)
    {
        printf("THE MEMORY IF FULL\n");
        return;
    }
    int ch;
    for(;;)
    {
     printf("ENTER THE CHOICE\n1.TO INSERT\n2.TO DELETE\n3.DISPLAY\n0.TO EXIT\n");
     scanf("%d",&ch);

     switch (ch)
     {
     case 1:insertcircular(&q);display(&q);break;
     case 2:deletecircular(&q);display(&q);break;
     case 3:display(&q);break;
     case 0:printf("THE PROGRAM TERMINATED\n");exit(0);
     default:printf("ENTER THE VALID CHOICE\n");
     }

    }

}

void main()
{
    circular();
}