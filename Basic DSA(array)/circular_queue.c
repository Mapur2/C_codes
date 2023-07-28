#include<stdio.h>
#include<stdlib.h>
void display(int *a,int n,int *f,int *r)
{
	printf("now f=%d r=%d\n",*f,*r);
	int i,t=*f;
	if((*r==-1) )
	printf("Array is empty\n");
	else
	{
		for(i=0;i<n;i++){
		if(t!=*r)
		{
			printf("%d ",a[t]);
			t=(t+1)%n;
		}
		else
		{
			printf("%d",a[*r]);
			break;
		}
	}
	}
	printf("\n");
}
void push(int *a,int n,int num,int *f,int *r)
{
	if((*r==*f-1 && *f!=0) || (*r==n-1 && *f==0))
	{
		printf("Arrays is full\n");
	}
	else
	{
		if(*f==-1)
			*f=*f+1;
		*r=(*r+1)%n;
		a[*r]=num;
		printf("now f=%d r=%d\n",*f,*r);
	}
}
void pop(int *a,int n,int *f,int *r)
{
	if(*r==-1 || (*r==*f-1 && *f!=0))
	{
		printf("array is empty\n");
	}
	else
	{
		if(*r==*f)
		{
			*r=-1;
			*f=-1;
		}
		*f=(*f+1)%n;
		printf("now f=%d r=%d\n",*f,*r);
	}
}
void main()
{
	int n,i,ch,num,*a,fl=-1;int *f=-1,*r=-1;
	printf("Enter the size of array");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(a)*n);
	while(1)
	{
		printf("enter 1 for push,2 for pop, 3 for display,4 for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the number\n");
				scanf("%d",&num);
				push(a,n,num,&f,&r);
				break;
			case 2:
				pop(a,n,&f,&r);
				break;
			case 3:
				display(a,n,&f,&r);
				break;
			case 4:
				fl=1;
				break;
			default:
				printf("Invalid input");
		}
		if(fl==1)
		break;
	}
}

