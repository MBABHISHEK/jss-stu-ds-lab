//Time program
#include<stdio.h>
#include<stdlib.h>
struct Time
{
int h,m,s;
};
typedef struct Time time;
void init(time *t)
{
t->h=t->s=t->m=0;
}
void read(time *t)
{
printf("Enter Hour : ");scanf("%d",&t->h);
printf("Enter Minute: ");scanf("%d",&t->m);
printf("Enter Second : ");scanf("%d",&t->s);
}
void display(time *t)
{
printf("%d:%d:%d\n",t->h,t->m,t->s);
}
void update(time *t)
{
t->s++;
if(t->s>=60)
{
t->m=t->m+t->s/60;
t->s=t->s%60;
if(t->m>=60)
{
t->h=t->h+t->m/60;
t->m=t->m%60;
if(t->h>=24)
init(t);
}
}
}

void add(time *t1,time *t2,time *t3)
{
t3->h=t1->h+t2->h;
t3->m=t1->m+t2->m;
t3->s=t1->s+t2->s;
t3->s--;
update(t3);
}
void main()
{
time t1,t2,t3;int ch;
init(&t1);init(&t2);init(&t3);
for(;;)
{
printf("1.Read Time\n2.Display\n3.Add\n4.Update\nEnter Your Choice:");scanf("%d",&ch);
switch (ch)
{
case 1:printf("ENTER TIME1\n");read(&t1);
printf("ENTER TIME2\n");read(&t2);
break;
case 2:printf("TIME1");display(&t1);
printf("TIME2");display(&t2);
break;
case 3:add(&t1,&t2,&t3);display(&t3);break;
case 4:update(&t1);printf("Time1\n");display(&t1);break;
default:
exit(0);
}
}
}
