/*Sorts while pushing in linked list*/

#include<stdio.h>
#include<stdlib.h>
struct link{
	int n;
	struct link *next;
};
typedef struct link node;
node* pushSort(node *head,int e)
{
	node *ele,*h,*p;
	int f=0;
	ele=(node *)malloc(sizeof(node));
	ele->n=e;
	ele->next=NULL;
	if(head==NULL)
	{
		head=ele;
	}
	else
	{
		if(e<head->n){
			ele->next=head;
			head=ele;
		}
		else{
			h=head;
			while(h!=NULL && h->n<=e){
				p=h;
				h=h->next;
			}
			ele->next=p->next;
			p->next=ele;
		}
	}
	return head;
}
void main()
{
	node *head,*t;
	head=NULL;
	int ch,e,f=0;
	while(f==0)
	{
		printf("enter 1 for push , 2 for exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the number ");
				scanf("%d",&e);
				head=pushSort(head,e);
				break;
			case 2:
				f=1;
				break;
		}
		t=head;
		while(t!=NULL)
		{
			printf("%d ",t->n);
			t=t->next;
		}
		printf("\n");
	}
}
/*
This is an alternative way but has more time complexity
node* pushSort(node *head,int e)
{
	node *ele,*h,*t;
	int f=0;
	ele=(node *)malloc(sizeof(node));
	ele->n=e;
	ele->next=NULL;
	if(head==NULL)
	{
		head=ele;
		return head;
	}
	else
	{
		if(head->n >= e)
			{
				ele->next=head;
				return ele;
			}
		h=head;
		while(h->next!=NULL)
		{	
			if(h->n <= e && h->next->n >= e)
			{
				f=1;
				t=h;
				t=t->next;
				h->next=ele;
				ele->next=t;
				break;
			}
			else
				h=h->next;
		}
		if(f!=1)
		{
			h->next=ele;
		}
		return head;
	}
}*/
