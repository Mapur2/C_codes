#include<stdio.h>
#include<stdlib.h>
int push(int *a,int n,int num,int f,int r)
{
	if(r==n-1)
	{
		printf("Array is full\n");
		return r;
	}
	else
	{
		r++;
		printf("Inserted at index %d\n",r);
		a[r]=num;
		return r;
	}
}
int pop(int *a,int n,int f,int r)
{
	int i;
	if(r==-1)
	{
		printf("Array is empty\n");
		return r;
	}
	printf("%d Popped\n",a[f]);
	for(i=f+1;i<=r;i++)
	a[i-1]=a[i];
	return --r;
}
void display(int *a,int f,int r)
{
	int i;
	if(r==-1)
	printf("Array is empty");
	else
	{
		for(i=f;i<=r;i++)
		printf("%d ",a[i]);
	}
	printf("\n");
}
void main()
{
	int n,i,ch,num,*a,f=0,r=-1,fl=0;
	printf("Enter the size of array");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(a)*n);
	while(fl==0)
	{
		printf("enter 1 for push,2 for pop, 3 for display,4 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the number\n");
				scanf("%d",&num);
				r=push(a,n,num,f,r);
				break;
			case 2:
				r=pop(a,n,f,r);
				break;
			case 3:
				display(a,f,r);
				break;
			case 4:
				fl=1;
				break;
			default:
				printf("Invalid input");
		}
		
	}
}
