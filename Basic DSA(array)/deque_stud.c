#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud{
	int rl;
	char ne[100];
	int t;
};
void frontdisplay(struct stud *s,int n,int f,int r)
{
    int i;
    if(r==-1)
    {
    	printf("Array is empty\n");
	}
	else{
    for(i=0;i<n;i++)
    {
        if(f!=r)
        {
            printf("\t%d %s %d ",s[f].rl,s[f].ne,s[f].t);
            f=(f+1)%n;
        }
        else{
            printf("\t%d %s %d ",s[r].rl,s[r].ne,s[r].t);
            break;
        }
        printf("\n");
    }
	}
}
void reardisplay(struct stud *s,int n,int f,int r)
{
    int i;
    if(r==-1)
    {
    	printf("Array is empty\n");
	}
	else{
    for(i=0;i<n;i++)
    {
        if(f!=r)
        {
            printf("\t%d %s %d ",s[r].rl,s[r].ne,s[r].t);
            if(r-1<0)
            r=n-1;
            else
            r--;
        }
        else{
            printf("\t%d %s %d ",s[f].rl,s[f].ne,s[f].t);
            break;
        }
         printf("\n");
    }
	}
}

int frontpush(struct stud *s,int n,int f,int r)
{
	if((f==0 && r==n-1) || f==r+1)
	{
		printf("Array is full");
		return f;
	}
	int roll,total;
	char nm[100];
	printf("enter roll,name,total\n");
	scanf("%d %s %d",&roll,&nm,&total);
	if(f==-1)
		f=0;
	else if(f-1<0)
		f=n-1;
	else
		f=f-1;
		
	s[f].rl=roll;
	strcpy(s[f].ne,nm);
	s[f].t=total;
	
	return f;
}
int rearpush(struct stud *s,int n,int f,int r )
{
    if((f==0 && r==n-1) || f==r+1)
    {
    printf("Array is full\n");
		return r;
	}
	int roll,total;
	char nm[100];
	printf("enter roll,name,total\n");
	scanf("%d %s %d",&roll,&nm,&total);
    if(r==-1)
        r=0;
    else 
        r=(r+1)%n;
        
    s[r].rl=roll;
	strcpy(s[r].ne,nm);
	s[r].t=total;
	
	return r;
}
int frontpop(struct stud *s,int n,int f,int r)
{
	if(f==-1)
	{
		printf("Array is empty");
		return f;
	}
	f=(f+1)%n;
	return f;
}
int rearpop(struct stud *s,int n,int f,int r)
{
	if(r==-1)
	{
		printf("Array is empty\n");
		return r;
	}
	if(r-1<0)
	r=n-1;
	else 
	r--;
	return r;
}
int main()
{
	struct stud *s;
	int f=-1,r=-1,fl=0,ch,cc,n;
	printf("Enter the length ");
	scanf("%d",&n);
	s=(struct stud*)malloc(sizeof(struct stud)*n);
	while(fl==0)
	{
		printf("Enter 1 for push , 2 for pop, 3 for,4 for exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter 1 for front push , 2 for rear push\n");
				scanf("%d",&cc);
				if(cc==1)
				{
					if(r==-1)
					r=0;
					f=frontpush(s,n,f,r);
				}
				else if(cc==2)
				{
					r=rearpush(s,n,f,r);
					if(f==-1)
					f=0;
				}
				break;
			 case 2:
				printf("enter 1 for front pop , 2 for rear pop\n");
				scanf("%d",&cc);
				if(cc==1)
				{
					f=frontpop(s,n,f,r);
					if(f==r+1 || (f==0 && r==n-1))
					{
						r=-1;
						f=-1;
					}
				}
				else if(cc==2)
				{
					r=rearpop(s,n,f,r);
					if(r==-1 || (f==0 && r==n-1) || (f==r+1))
					{
						f=-1;
						r=-1;
					}
				}
				break;
			case 3:
				printf("enter 1 for  from-front , 2 for from-rear\n");
				scanf("%d",&cc);
				if(cc==1)
				frontdisplay(s,n,f,r);
				else if(cc==2)
				reardisplay(s,n,f,r);
			    break;
			case 4:
				fl=1;
				break;
			default :
				printf("Invalid input\n");
		}
		printf("\n now f=%d r=%d\n",f,r);
	}
    return 0;
}
