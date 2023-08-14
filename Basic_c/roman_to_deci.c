#include<stdio.h>
#include<string.h>
void roman(char [],int [],char []);
int last(char,char);
void display(char[]);
void main()
{
	char r[7]={'I','V','X','L','C','D','M'},s[100];
	int d[]={1,5,10,50,100,500,1000};
	printf("enter a roman number in capital letter like IV, VIII,etc \n");
	scanf("%s",&s);
	//roman(r,d,s);
	display(s);
}
void display(char s[]){
	int value[100];
	int i,j,sum=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='I')
			value[i]=1;
		else if(s[i]=='V')
			value[i]=5;
		else if(s[i]=='X')
			value[i]=10;
		else if(s[i]=='L')
			value[i]=50;
		else if(s[i]=='C')
			value[i]=100;
		else if(s[i]=='D')
			value[i]=500;
		else if(s[i]=='M')
			value[i]=1000;
		
			
	}
	for(j=0;j<i-1;j++){
		if(value[j]<value[j+1])
			value[j]=-value[j];
	}
	for(j=0;j<i;j++)
		sum=sum+value[j];
	printf("%d",sum);
}
void roman(char r[],int d[],char s[])
{
	int i=0,su=0,j=0,l=strlen(s),la,f=0,t;
	
	for(i=0;i<l;i++)
	{
		la=last(s[i],s[i+1]);
		if(la!=0)
		{su=su+la;
			++i;
		}
		else
		{
		for(j=0;j<7;j++)
		{
			if(s[i]==r[j]) 
			su+=d[j];
		}
		}
	}
	printf("%d",su);
	
}
int last(char a,char b)
{
	if(a=='I' && b=='V')
		return 4;
	else if(a=='I' && b=='X')
		return 9;
	else if(a=='X' && b=='L')
		return 40;
	else if(a=='X' && b=='C')
		return 90;
	else if(a=='C'&& b=='D')
	return 400;
	else if(a=='C' && b=='M')
	return 900;
	else return 0;
}
