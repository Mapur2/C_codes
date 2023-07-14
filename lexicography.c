#include<stdio.h>
#include<string.h>
void main()
{
	char s[100],w[10][100],t[100],wd[20];
	int i,j=0,n=0,k,p,c,f[10],ty,h=0,fl=0,in=0;
	
	printf("enter\n");
	gets(s);
	strcat(s," ");
	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		wd[j++]=s[i];
		else
		{
			wd[j]='\0';
			j=0;
			if(n==0)
			{
			 f[n]=0;
			 strcpy(w[n],wd);
			 ++f[n];//printf("\n n=%d %d",n,f[n]);
			 n++;
			 f[n]=0;
			}
			else
			{
				fl=0;
			for(k=0;k<n;k++)
			{
				if(strcmp(w[k],wd)!=0)
				{
					fl=1;
				}
				else if(strcmp(w[k],wd)==0)
				{
					fl=0;
				in=k;
				break;}
			}
			if(fl==1)
			{//printf("store new at n %d",n);
			strcpy(w[n],wd);
			++f[n];//printf("\n%s",w[n]);
			n++;
			f[n]=0;
			//printf("\n increased n=%d",n);
		    }
		    else
		    {
		    	++f[in];
		    	//printf("\n increase f at %d\n",in);
			}
			}
		}
	}
	//for(i=0;i<n;i++)
	//printf("\n%s=%d",w[i],f[i]);
	printf("\n");
	p=n;
	for(i=0;i<p-1;i++)
	{
		for(h=0;h<p-1-i;h++)
		{
			if(f[h]<f[h+1])
			{
				ty=f[h];
				f[h]=f[h+1];
				f[h+1]=ty;
				
				strcpy(t,w[h]);
				strcpy(w[h],w[h+1]);
				strcpy(w[h+1],t);
			}
			else if(f[h]==f[h+1] && strcmp(w[h+1],w[h])<0)
			{
				strcpy(t,w[h]);
				strcpy(w[h],w[h+1]);
				strcpy(w[h+1],t);
			}
		}
    }
    for(i=0;i<p;i++)
	printf("\n%s=%d",w[i],f[i]);
}

			
