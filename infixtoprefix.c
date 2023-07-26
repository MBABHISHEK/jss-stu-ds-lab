#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size=30;
struct stack1
{
char item[30];
int top;
};
typedef struct stack1 oprstk;
struct stack2
{
char item[20][30];
int top;
};
typedef struct stack2 opndstk;
void push1(char c,oprstk *s)
{
if(s->top==size-1)
printf("OVERFLOW\n");
else
s->item[++s->top]=c;
}
char pop1(oprstk *s)
{
if(s->top==-1)
printf("UNDERFLOW\n");
else
return(s->item[s->top--]);
}
void push2(char c[],opndstk *s)
{
if(s->top==size-1)
printf("OVERFLOW\n");
else
strcpy(s->item[++s->top],c);
}
char * pop2(opndstk *s)
{
char *c;
if(s->top==-1)
printf("UNDERFLOW\n");
else{
c=(s->item[s->top--]);return c;

}
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
int inprc(char c)
{
switch(c)
{
case '+':
case '-':return 1;
case '*':
case '/':return 3;
case '^':
case '$':return 7;
case '(':return 8;
case ')':return 0;
}
}
int stkprc(char c)
{
switch(c)
{
case '+':
case '-':return 2;
case '*':
case '/':return 4;
case '^':
case '$':return 6;
case '(':return 0;
}
}
void par(oprstk *s1,opndstk *s2)
{
char opr=pop1(s1);char temp[2];
temp[0]=opr;temp[1]='\0';
char *op2=pop2(s2);
char *op1=pop2(s2);
char preexp[3];
strcpy(preexp,temp);
strcat(preexp,op1);
strcat(preexp,op2);
push2(preexp,s2);

}
void intopre(char in[],char pre[])
{
int i=0;char c,temp[2];
oprstk s1;
opndstk s2;
s1.top=s2.top=-1;
while((c=in[i++])!='\0')
{
if(isoperand(c))
{
temp[0]=c;temp[1]='\0';push2(temp,&s2);
}
else
{
while(s1.top!=-1 && stkprc(s1.item[s1.top])>inprc(c))
{
if(c==')')
{
while(s1.item[s1.top]!='(')
par(&s1,&s2);
pop1(&s1);
break;
}
par(&s1,&s2);
}
if(c!=')')
push1(c,&s1);
}
}
while(s1.top!=-1)
par(&s1,&s2);
strcpy(pre,s2.item[s2.top]);
}
void main()
{
char in[30],pre[30];
for(;;)
{
printf("Enter Exp 0 to Terminate : ");
scanf("%s",in);
if(strcmp(in,"0")==0)
break;
intopre(in,pre);
printf("Prefix is : %s\n",pre);
}
}
