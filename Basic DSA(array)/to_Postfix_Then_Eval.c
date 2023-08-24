/*converts infix to postfix then evaluates*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 20
typedef struct{
	int top;
	int val[MAX];
}eval;
typedef struct 
{
	int top;
	char stk[MAX];
}stack;
void push(stack *s,char p)
{
	s->top++;
	s->stk[s->top]=p;
}
void pop(stack *s)
{
	if(s->top==-1)
		s->top=-1;
	else
		s->top--;
}
int checkOperator(char p)
{
	if(p=='+' || p=='-')
		return 1;
	else if(p=='/' || p=='*')
		return 2;
	else if(p=='^')
		return 3;
}
int isOperand(char ch)
{
	if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
		return 1;
	return 0;
}
void I_to_P(char q[],char *p)
{
	stack s;
	int i=0,f=0,k=0,j=0;
	s.top=-1;
	push(&s,'(');
	strcat(q,")");
	while(q[i]!='\0')
	{	
		if(s.top==-1)
			push(&s,'(');
		if(q[i]==' ')
		{
			i++;
			continue;
		}
		if(isOperand(q[i])==1)
			p[k++]=q[i];
		else 
		{
			if(s.stk[s.top]=='(')
				push(&s,q[i]);
			else if(q[i]==')')
			{
				while(s.stk[s.top]!='(')
				{
						pop(&s);
						p[k++]=s.stk[s.top+1];
				}
				pop(&s);
			}
			else
			{
				if(checkOperator(s.stk[s.top])<checkOperator(q[i]))
					push(&s,q[i]);
				else if(checkOperator(s.stk[s.top]) >= checkOperator(q[i]))
				{			
					while(checkOperator(s.stk[s.top]) >= checkOperator(q[i]) && s.top!=-1 && s.stk[s.top]!='(')
					{
						p[k++]=s.stk[s.top];
						pop(&s);
					}
					push(&s,q[i]);
				}
			}
		}
		i++;
	}
	p[k]='\0';
}
int evaluate(char *p)
{
	eval es;
	es.top=-1;
	int i=0,value=0,a,b;
	while(p[i]!='\0')
	{
		if(isOperand(p[i])==1)
		{
			printf("enter the value of %c ",p[i]);
			scanf("%d",&value);
			es.top++;
			es.val[es.top]=value;
		}
		else
		{
			a=es.val[es.top-1];
			b=es.val[es.top];
			es.top--;
			if(p[i]=='+')
				value=a+b;
			if(p[i]=='-')
				value=a-b;
			else if(p[i]=='*')
				value=a*b;
			else if(p[i]=='/')
				value=a/b;
			else if(p[i]=='^')
				value=pow(a,b);
			es.val[es.top]=value;
		}
		i++;
	}
	printf("Stack= ");
	for(value=0;value<=es.top;value++)
		printf("%d",es.val[value]);
	printf("\n");
	return es.val[es.top];
}
void  main()
{
	int evaluat;
	char q[20],*p;
	p=(char *)malloc(sizeof(p)*MAX);
	printf("enter the equation : ");
	gets(q);
	I_to_P(q,p);
	printf("%s\n",p);
	evaluat=evaluate(p);
	printf("%d",evaluat);
}
