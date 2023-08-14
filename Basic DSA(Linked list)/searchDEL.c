#include<stdio.h>
#include<stdlib.h>
struct link
{
	int n;
	struct link *ad;
};
typedef struct link node;
struct link* searchDelete(node *head,int num)
{
	node *h;
	if(head == NULL){
		printf("Empty list");
		return head;
	}
	while(head!=NULL && head->n==num)
		head=head->ad;
	h=head;
	if(head==NULL)
		return head;
	while(h->ad!=NULL){
		if(h->ad->n==num){
			h->ad=h->ad->ad;
		}
		else
			h=h->ad;
	}
	return head;
}
struct link* push(struct link* head,int num)
{
	struct link *p,*h;
	p=(struct link*)malloc(sizeof(struct link));
	p->n=num;
	p->ad=NULL;
	if(head==NULL)
	head=p;
	else
	{
		h=head;
		while(h->ad!=NULL)
		{
			h=h->ad;
		}
		h->ad=p;
	}
	return head;
}
int main()
{
	struct link *h,*t;
	h=NULL;
	int ch,f=0,num,s;
	while(f==0)
	{
		printf("\nenter 1 for push , 2 for search and delete ,3 dor exit\n");
		scanf("%d" ,&ch);
		switch(ch)
		{
			case 1:
				scanf("%d",&num);
				h=push(h,num);
				break;
			case 2:
				printf("Enter search number ");
				scanf("%d",&s);
				h= searchDelete(h,s);
				break;
			case 3:
				f=1;
		}
		t=h;
		while(t!=NULL)
		{
		printf("%d ",t->n);
		t=t->ad;
		}
	}
}
