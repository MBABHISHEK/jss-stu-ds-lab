#include<stdio.h>
#include<conio.h>
#include<string.h>
int size=30,flag=0;
struct stack
{
char item[30];
int top;
};
typedef struct stack stk;
int isoperand(char c)
{
switch (c)
{
case '+':
case '-':
case '*':
case '/':
case '$':
case '^':
case '(':
case ')':return 0;
default:return 1;
}
}
void push(char c,stk *s)
{
if(s->top==size-1)
printf("OVERFLOW");
else
s->item[++s->top]=c;
}
char pop(stk *s)
{
if(s->top==-1)
printf("UNDERFLOW");
else
return(s->item[s->top--]);
}
int stkprc(char c)
{
switch (c)
{
case '+':
case '-':return 2;
case '*':
case '/':return 4;
case '$':
case '^':return 5;
case '(':return 0;
}
}
int inprc(char c)
{

switch (c)
{
case '+':
case '-':return 1;
case '*':
case '/':return 3;
case '$':
case '^':return 6;
case '(':return 9;
case ')':return 0;
}
}
void inpost(char in[],char po[])
{
stk s;s.top=-1;int i=0,j=0;char c;
while((c=in[i++])!='\0')
{
if(isoperand(c))
po[j++]=c;
else
{
while(s.top!=-1 && stkprc(s.item[s.top])>inprc(c))
{
if(c==')')
{
while(s.item[s.top]!='(')
{
po[j++]=pop(&s);
}
pop(&s);
break;
}
else
po[j++]=pop(&s);
}
if(c!=')')
{
push(c,&s);
}
}
}
while(s.top!=-1)
{
po[j++]=pop(&s);
}
po[j]='\0';
}
void main()
{
char in[30],po[30];
for(;;)
{
printf("Enter Expression or 0 to Terminate : ");
scanf("%s",in);
if(strcmp(in,"0")==0)

{
break;
}
inpost(in,po);
printf("Postfix Expression is : %s\n",po);
}
}
