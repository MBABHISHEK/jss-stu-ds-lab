#include<stdio.h>
#include<stdlib.h>

struct Queue
{
   int * item;
   int f,r,count,size;
};


typedef struct Queue * QUE;


void insertcircular(QUE q)
{

  if(q->count==q->size)
  {
      int *a=(int *)malloc(q->size*sizeof(int));
     int i=q->f,j;
    j=0;
    int k=0;

  while(j<q->count)
  {
    printf("hai abhi");
     *(a+k)=*(q->item+i);
     i=(i+1)%q->size;
     j++;
     k++;
  }
    free(q->item);
    q->r=q->size-1;
    q->size*=2;//q->size=q->size*2;
    printf("THE MEMORY FULL REALLOCATION");
    q->item=(int*)realloc(a,sizeof(int)*q->size);
    q->f=0;
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
  while(j<q->count)
  {
     printf("%d ",*(q->item+i));
     i=(i+1)%q->size;
     j++;

  }
  printf("\n");
}


void circular()
{
 struct Queue q;
 q.count=0;
 q.f=0;
 q.r=-1;
  printf("ENTER THE SIZE OF THE QUEUE\n");
  scanf("%d",&q.size);

  q.item=(int *)malloc(q.size*sizeof(int));
  if(q.item==NULL)
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
void doubleended()
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


    void main()
{
    int ch;
   
    for(;;)
    {
         printf("ENTER THE CHOICE \n1.TO DOUBLE EANDED QUEUE\n2.TO CIRCULAR QUEUE\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1: doubleended(); break;
    case 2: circular(); break;
    default:printf("ENTER THE VALID CHOICE \n");
    }
    }

}

