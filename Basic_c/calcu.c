/*can take as many inputs you want*/

#include<stdio.h>
void main()
{
	int c=1;
	float n,s=0.0,su=0.0,m=1.0,d=1.0;
	do
	{
		printf("enter your number");
		scanf("%f",&n);
		printf("enter 1 for sum 2 for sub 3 for - 4 for / , 5 to exit");
		scanf("%d",&c);
		if(c==1)
		{
			s=s+n;
			printf("%f\n",s);
		}
		else if(c==2)
		{
			s=s-n;
			printf("%f\n",s);
		}
		else if(c==3)
		{
			if(s==0.0)
			s=1.0;
			s=s*n;
			printf("%f\n",s);
		}
		else
		{
			if(s==0.0)
			s=1.0;
			s=s/n;
			printf("%f\n",s);
		}
	}while(c!=5);
}
