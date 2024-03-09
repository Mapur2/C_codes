#include<stdio.h>
#include<stdlib.h>
int count(int *a,int n)
{
	int c=0,d,i;
	int m=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>m)
		m=a[i];
	}
	while(m!=0)
	{
		c++;
		m/=10;
	}
	return c;
}
void sort(int *a,int n,int m)
{
	int *p,k=0;
	p=(int*)malloc(n*sizeof(int));//array where elements will be inserted
	int j=0,i=0,l,c=1,mi=1,puin;//puin is push index
	while(mi<=m)
	{
		mi++;
		puin=0;k=0;
		for(i=0;i<10;i++)
		{
		for(j=0;j<n;j++)
		{
			if((a[j]/c)%10==i) 
				p[puin++]=a[j]; //inserting in the new array one by one if condition satisfies
		}
		}
		for(j=0;j<n;j++)
		a[j]=p[j]; //copying the new array in old array
		c*=10;
	}
}
int main()	
{
	int *a,i,n;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	 int m=count(a,n);
	sort(a,n,m);
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
