#include<stdio.h>
#include<stdlib.h>
int push(int *a,int n,int t,int num)
{
	if(t==n-1)
	{
		printf("Stack is full");
		return t;
	}
	t++;
	a[t]=num;
	return t;
}
int pop(int *a,int n,int t)
{
	if(t==-1)
	{
		printf("Stack is empty\n");
		return t;
	}
	t--;
	return t;
}
void display(int *a,int t)
{
	int i;
	if(t==-1)
	printf("Stack is empty\n");
	else
	{
		for(i=0;i<=t;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}
int main()
{
	int t=-1,*a,n,ch,f=0,num;
	printf("Enter length ");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(a)*n);
	while(1)
	{
		printf("enter your choice 1 for push 2 pop 3 for display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number\n");
				scanf("%d",&num);
				t=push(a,n,t,num);
				break;
			case 2:
				t=pop(a,n,t);
				break;
			case 3:
				display(a,t);
				break;
			default:
				printf("Invalid input");
				f=1;
		}
		if(f==1)
		break;
	}
}
