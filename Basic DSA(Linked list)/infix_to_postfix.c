#include<stdio.h>
#include<string.h>
#define MAX 20
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
int main()
{
	stack s;
	char q[20],p[20];
	int i=0,f=0,k=0,j=0;
	printf("enter the equation : ");
	gets(q);
	s.top=-1;
	push(&s,'(');
	strcat(q,")");
	while(q[i]!='\0')
	{	
		if(s.top==-1)
			push(&s,'(');
		printf("top=%d\n",s.top);
		if(q[i]==' ')
			continue;
		if(isOperand(q[i])==1)
			p[k++]=q[i];
		else 
		{
			if(s.stk[s.top]=='(')
				push(&s,q[i]);
			else if(q[i]==')')
			{
				printf("found )");
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
		printf("p= ");
		for(j=0;j<=k;j++)
			printf("%c",p[j]);
		printf("\n");
		printf("stk= ");
		for(j=0;j<=s.top;j++)
			printf("%c",s.stk[j]);
		printf("\n");
		i++;
	}
	p[k]='\0';
	printf("\n%s",p);
}
