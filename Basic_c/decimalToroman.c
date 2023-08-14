#include<stdio.h>
void decimal(int ,int);
void main()
{
	char r[][3]={"I","IV","V","IX","X","XL","L","LC","C","CD","D","CM","M"};
	int d[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	int n;
	int div=1000,q,i,m,flag,dif;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	while(div!=0)
	{
		q=n/div;
		n=n%div;
		if(div==1000)
		{
			if(q!=0){
				for(i=1;i<=q;i++)
					printf("M");
			}
		}
		else if(div==100)
		{
			m=q*100;
			flag=0;
			for(i=8;i<=11;i++){
				if(d[i]==m){
					printf("%s",r[i]);
					flag=1;
					break;
				}
			}
			if(flag==0){
				if(q>5){
					printf("D");
					dif=q-5;
				}
				else
					dif=q;
				
				for(i=1;i<=dif;i++)
					printf("C");
				
			}
		}
		else if(div==10)
		{
			m=q*10;
			flag=0;
			for(i=4;i<=7;i++){
				if(d[i]==m){
					printf("%s",r[i]);
					flag=1;
					break;
				}
			}
			if(flag==0){
				if(q>5){
					printf("L");
					dif=q-5;
				}
				else
					dif=q;
				
				for(i=1;i<=dif;i++)
					printf("X");
				
			}
		}
		else
		{
			m=q;
			flag=0;
			for(i=0;i<4;i++)
			{
				if(d[i]==m)
				{
					printf("%s",r[i]);
					flag=1;
					break;
				}
			}
			if(flag==0){
				if(q>5)
				{
					printf("V");
					dif=q-5;
				}
				else
					dif=q;
				
				for(i=1;i<=dif;i++)
					printf("I");
				
			}	
		}
		div=div/10;
	}
	
}

