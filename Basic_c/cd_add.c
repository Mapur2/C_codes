/*takes input from cmd (as a string). Can add two positive integers*/

#include<stdio.h>
#include<string.h>
int main(int c,char *n[])
{
	//printf("%c",49);
	if(c!=3)
	printf("Invalid Input");
	else
	{
		int l1=strlen(n[1]),l2=strlen(n[2]),l3,l4,i=0,j=0,c=0,s=0;
		l3=(l1>l2)?l1:l2;
		l3=l3+1;
		l4=l3;
		char a[100];
		a[l3]='\0';
		l3--;
		l1--;l2--;
		while(l1!=-1 && l2!=-1)
		{
			if(n[1][l1]>='0'&&n[1][l1]<='9' &&n[2][l2]>='0' && n[2][l2]<='9')
			{
			s=(n[1][l1]-48)+(n[2][l2]-48)+c;
			//printf("%d",s);
			if(s>9)
			{
				c=1;
				s=s-10;
			}
			else
			c=0;		
			a[l3]=s+48;
			//printf("%c",a[l3]);
			l3--;
			l1--;
			l2--;
			}
			else
			{
				printf("Invalid Input");
				return 0;
			}	
		}
		while(l1!=-1)
		{
			
			if(n[1][l1]>='0'&&n[1][l1]<='9')
			{
			s=(n[1][l1]-48)+c;
			if(s>9)
			{
				c=1;
				s=s-10;
			}
			else
			c=0;
			a[l3]=s+48;
			//	printf("%c\n",a[l3]);
			l3--;
			l1--;
			}
			else
			{
				printf("Invalid Input");
				return 0;
			}	
		}
		while(l2!=-1)
		{
			if(n[2][l2]>='0' && n[2][l2]<='9')
			{
			s=(n[2][l2]-48)+c;
			if(s>9)
			{
				s=s-10;
				c=1;
			}
			else
			{
				c=0;
			}
			a[l3]=s+48;
			//printf("%c\n",a[l3]);
			l3--;
			l2--;
			
			}
			else
			{
				printf("Invalid Input");
				return 0;
			}
		}
		if(c!=0)
		{
			a[l3]=c+48;
			i=0;
		}
		else
		a[0]=' ';
		
		printf("%s\n",a);	
	}
}

