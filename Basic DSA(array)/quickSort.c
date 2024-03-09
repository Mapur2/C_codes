
#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int l, int r)
{
	int p=a[l],t;
	int i=l+1,j=r;
	while(i<=j)
	{
		while(i<=r && a[i]<p)
		{
			i++;
		}
	 	while(j>=l && a[j]>p)
		{
			j--;
		}
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
		t=a[j];
		a[j]=a[l];
		a[l]=t;
	return j;
}
void sort(int a[],int l,int r)
{
	int j;
	if(l<r){
		j=partition(a,l,r);
		sort(a,j+1,r);
		sort(a,l,j-1);
	}
	else
		return;
}
void main()
{
	int i,j,k,n,*a,l,r;
	printf("enter your numbers :");
	scanf("%d",&n);
	printf("Enter the array\n");
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	l=0;r=n-1;
	sort(a,l,r);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
