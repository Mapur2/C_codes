#include<stdio.h>
#include<stdlib.h>
void shell(int *a,int n);
int main()
{
	int n,i,*a;
	printf("Enter the size ");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(a)*n);
	printf("Enter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	shell(a,n);
	printf("Sorted ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void sort(int *a,int n,int d,int j)
{
	int i,p,t,m=n/d,k,l=0;
	p=j+d;
	if(p>=n)
		return;
	//Like insertion sort
	for(i=p;l<m && i<n;i=i+d)
	{
		k=a[i];
		t=i-d;
		while(t>=j && a[t]>k)
		{
			a[t+d]=a[t];
			t=t-d;
		}
		a[t+d]=k;
		l++;
	}
}
void shell(int *a,int n)
{
	int i,j,l;
	int d=n/2;
	while(d!=0)
	{
		for(j=0;j<d;j++)
			sort(a,n,d,j);
		d/=2;
	}
}
