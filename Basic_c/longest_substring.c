#include<stdio.h>
#include<string.h>
void main()
{
	//longest common substring
	char s[100],n[100],m[20],w[20];
	int i=0,j=0,l,k=0,len,p,mi=0,we;
	printf("enter two strings\n");
	gets(s);
	gets(n);
	for(i=0;i<strlen(s);i++)
	{
		for(j=0;j<strlen(n);j++)
		{
			
			if(s[i]==n[j])
			{p=i,we=j;
				while(1)
				{
					if(s[p]==n[we])
					w[mi++]=s[p];
					else break;
					we++;p++;
				}
				w[mi]='\0';
				
				if(strlen(m)<=strlen(w))
				strcpy(m,w);
				mi=0;
			}
		}
	}
	printf("\n%s",m);
}
