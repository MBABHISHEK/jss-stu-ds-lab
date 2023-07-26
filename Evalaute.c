#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int size=30;
struct stack

{
float item[30];
int top;
};
typedef struct stack stk;
void push(float c,stk *s)
{
if(s->top==size-1)
printf("OVERFLOW\n");
else
s->item[++s->top]=c;
}
float pop(stk *s)
{
if(s->top==-1)
printf("UNDERFLOW\n");
else
return(s->item[s->top--]);
}
int isoperand(char c)
{
switch(c)
{
case '+':
case '-':
case '*':
case '/':
case '^':
case '$':
case '(':
case ')':return 0;
default:return 1;
}
}
float compute(float op1,float op2,char c)
{
switch(c)
{
case '+':return(op1+op2);
case '-':return(op1-op2);
case '*':return(op1*op2);
case '/':return(op1/op2);
case '^':
case '$':return(pow(op1,op2));
}
}
void Evaluate_Post(char po[])
{
int i=0;char c;stk s;s.top=-1;float op1,op2,res;
while((c=po[i++])!='\0')
{
if(isoperand(c))
push(c-'0',&s);
else
{

op2=pop(&s);
op1=pop(&s);
res=compute(op1,op2,c);
push(res,&s);
}
}
res=pop(&s);
if(s.top!=-1)
printf("Invalid\n");
else
printf("Value is : %f\n",res);
}
void Evaluate_Pre(char pre[])
{
int i=strlen(pre)-1;char c;stk s;s.top=-1;float op1,op2,res;
while(i>=0)
{
c=pre[i];
if(isoperand(c))
push(c-'0',&s);
else
{
op1=pop(&s);
op2=pop(&s);
res=compute(op1,op2,c);
push(res,&s);
}
i--;
}
res=pop(&s);
if(s.top!=-1)
printf("Invalid\n");
else
printf("Value is : %f\n",res);
}
void main()
{
char po[30],pre[30];int ch;
for(;;)
{
printf("1.Evalute Postfix\n2.Evaluate Prefix\nEnter Your Choice : ");scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter Expreesion and 0 to Terminate : ");scanf("%s",po);
if(strcmp(po,"0")==0) break;
Evaluate_Post(po);
break;
case 2:printf("Enter Expreesion and 0 to Terminate : ");scanf("%s",pre);
if(strcmp(po,"0")==0) break;
Evaluate_Pre(pre);
break;
default:exit(1);
}
}
}
