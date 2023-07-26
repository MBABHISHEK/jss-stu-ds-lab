#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[30];
int regno;
int m[3];
float avg;
};
int n=0;
typedef struct student STU;
void read(STU *s)
{
for(int i=0;i<n;i++)
{
printf("Enter Details of Student %d\n",i+1);
printf("Enter Name : ");scanf("%s",(s+i)->name);
printf("Enter Register Number : ");scanf("%d",&(s+i)->regno);
printf("Enter Test1 Test2 Test3 Marks : ");
for(int j=0;j<3;j++)
{
scanf("%d",&(s+i)->m[j]);
}
}

}
void avg(STU *s)
{
for(int i=0;i<n;i++)
{
int sum=((s+i)->m[0])+((s+i)->m[1])+((s+i)->m[2]);int min=(s+i)->m[0];
for(int j=0;j<3;j++)
{
if((s+i)->m[j]<min)
{
min=(s+i)->m[j];
}
}
(s+i)->avg=sum/3.0;
}
}
void display(STU *s)
{
printf("Regno\t\tName\t\tTest1\t\tTest2\t\tTest3\t\tAverage\n---------------------------------------------------------------\
n");
for(int i=0;i<n;i++)
{
printf("%d\t%s\t",(s+i)->regno,(s+i)->name);
for(int j=0;j<3;j++)
{
printf("%d\t\t",(s+i)->m[j]);
}
printf("%f\n",(s+i)->avg);
}
}
void main()
{
printf("Enter the Number of Students : ");scanf("%d",&n);
STU *s=((STU *)malloc(sizeof(STU)*n));int ch;
for(;;)
{
printf("1.Read Details of %d Students\n2.Display\nEnter Your Choice:",n);scanf("%d",&ch);
switch (ch)
{
case 1:read(s);break;
case 2:avg(s);display(s);break;
default:exit(1);
}
}
}
