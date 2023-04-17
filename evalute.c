#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stack{

    float item[20];
    int top;
};

typedef struct stack * stk;


void push(stk s,float c)
{
   if(s->top==19)
   {
    printf("THE STACK OVERFLOW\n");
   }

   s->top++;
   s->item[s->top]=c;
}

float pop(stk s)
{
    if(s->top==-1)
    {
        printf("THE STACK FLOW\n");
    }

    float c=s->item[s->top];
    s->top--;
    return c;
}

int isoprand(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '&':return 0;
  default:return 1;
  }
}

float compute(float op1, float op2,char c)
{
  switch (c)
  {
  case '+':return op1+op2;
  case '-':return op1-op2;
  case '/':return op1/op2;
  case '*':return op1*op2;
  case '^':
  case '&':return(pow(op1,op2));
  }
}



void evaluatepost(char post[])
{
   struct stack s;
   s.top=-1;
   int i=0;
   char c;
   float op1,op2,result;

   while((c=post[i++])!='\0')
   {
     if(isoprand(c))
     {
        float op=c-'0';
        push(&s,op);
     }
     else
     {
         
         op2=pop(&s);
         op1=pop(&s);
         result=compute(op1,op2,c);
         push(&s,result);
     }
   }
  result=pop(&s);
  printf("THE RESULT IS: %f\n",result);
}

void evaluatepre(char pre[])
{
   struct stack s;
   s.top=-1;
   int i=strlen(pre);
   char c;
   float op1,op2,result;
   i=i--;

   while((i>=0))
   {
      c=pre[i--];
     if(isoprand(c))
     {
        float op=c-'0';
        push(&s,op);
     }
     else
     {
         op1=pop(&s);
         op2=pop(&s);
         result=compute(op1,op2,c);
         push(&s,result);
     }


   }
  result=pop(&s);
  printf("THE RESULT IS: %f\n",result);
}

void main()
{

    int ch;
  for(;;)
  {
    printf("ENTER THE CHOICE 1.TOEVALUTE PRE\n2.TOEVALUTEPOST\n0.TO EXIT\n");
    //scanf("%d",&ch);
    ch=1;

    switch(ch)
    {
      case 1:printf("ENTER THE PREFIX EXPRESSION\n");
      char pre[20];
     // scanf("%s",pre);
       strcpy(pre,"+12*3");
      evaluatepre(pre);break;
      case 2:printf("ENTER THE POSTFIX EXPRESSION\n");
      char post[20];
      scanf("%s",post);
      evaluatepost(post);break;
      default:exit(1);
    }


  }

}