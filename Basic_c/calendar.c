#include<stdio.h> 
#include<string.h>
int firstDay(char mt[],int y)
{
	int i,j,k,s=0;
	char d[][7]={"mon","tue","wed","thu","fri","sat","sun"},month[][12]={"Jan","Feb","Mar","Apr","May"
	,"Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	for(i=1900;i<y;i++)
	{
		if((i%100!=0 && i%4==0) || i%400==0)
		s=s+366;
		else
		s+=365;
	}
	for(i=0;i<12;i++)
	{
		if(strcmp(month[i],mt)==0)
		break;
		if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11)
		s+=31;
		else if(i==1)
		s+=28;
		else 
		s+=30;
	}
	if(((y%100!=0 && y%4==0) || y%400==0) && i>1)
	s=s+2;
	else
	s+=1;
	//printf("%d\n",s);
	k=s%7;
	k=k-1;
	if(k<0)
	k=6;
	//printf("%d\n",k);
	if(k>=7)
	k=k-7;
	//printf("%d\n",k);
	//printf("%s\n",d[k]);
	return k;
}
void main()
{
	int y,d=1,i,c=0,ld,k,p;
	char mt[]="Jan",month[][12]={"Jan","Feb","Mar","Apr","May"
	,"Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	printf("enter year: ");
	scanf("%d",&y);
	for(p=0;p<12;p++)
	{
	d=1;c=0;
	k=firstDay(month[p],y);
	printf("\n\n\t\t\t%s\n",month[p]);
	if(p==0 || p==2 || p==4 || p==6 || p==7 || p==9 || p==11)
	ld=31;
	else if(((y%100!=0 && y%4==0) || y%400==0)&& p==1)
	ld=29;
	else if(p==1)
	ld=28;
	else
	ld=30;
	//printf("%d",ld);
	printf("Mon\tTue\tWed\tThurs\tFri\tSat\tSun\n");
	if(k!=0)
	{
	for(i=0;i<k;i++) 
		printf("\t");
	for(i=k;i<7;i++)
	{
		printf("%d\t",d);
		d++;
	}
	printf("\n");
 	}
	for(i=d;i<=ld;i++)
	{
		c++;
		printf("%d\t",i);
		if(c==7)
		{
		printf("\n");
		c=0;
		}
	}
	printf("\n");
   }
}
