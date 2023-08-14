#include<stdio.h>
#include<string.h>
void main()
{
	char s[100],n[100],m[20],w[20];
	int i=0,j=0,l,k=0,len,p,mi=0,we,x=0;
	printf("enter a strings\n");
	gets(s);
	for(i=strlen(s)-1;i>=0;i--)
	n[x++]=s[i];
	n[x]='\0';
	//printf("%s",n);
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

