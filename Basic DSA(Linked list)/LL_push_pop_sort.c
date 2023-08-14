/* Push from rear, push from front , pop from rear, pop from front and sorts the list*/

#include<stdio.h>
#include<stdlib.h>
struct link
{
	int n;
	struct link *nt;
};
void sort(struct link *head)
{
	if(head==NULL)
	printf("Empty Link\n");
	else
	{
		struct link *p,*t,*t1,*q;
		int m;
		t1=NULL;
		p=head;
		while(p!=NULL)
		{
			t=p->nt;
			q=p;
			while(t!=NULL)
			{
				if(q->n > t->n)
				{
					m=t->n;
					t1=t;
					q=t;
				}
				t=t->nt;
			}
			if(t1!=NULL)
			{
				t1->n=p->n;
				p->n=m;
			}
			p=p->nt;
			t1=NULL;
		}
	printf("\nNEW LINK  ");
			q=head;
			while(q!=NULL)
			{
				printf("%d ",q->n);
				q=q->nt;
			}
	printf("\n");
	}
}
void display(struct link *head)
{
	struct link *p;	
	p=head;
	if(p==NULL)
	printf("Empty link");
	else
	{
	while(p!=NULL)
	{
		printf("%d ",p->n);
		p=p->nt;
	}
	}
	printf("\n");
}
struct link * popfront(struct link* h)
{
	if(h==NULL)
	{
		printf("Empty link\n");
		return NULL;
	}
	if(h->nt==NULL)
	return NULL;
	h=h->nt;
	return h;
}
struct link * pop(struct link* h)
{
	struct link *p,*d;
	p=h;
	if(p==NULL)
	{
		printf("Empty link\n");
		return NULL;
	}
	if(p->nt==NULL)
	{
		return NULL;
	}
	while(1)
	{
		if(p->nt->nt==NULL)
		{
			p->nt=NULL;
			break;
		}
		p=p->nt;
	}
	return h;
}
struct link* push(int num,struct link *head)
{
	struct link *p,*h;	
	p=(struct link*)malloc(sizeof(struct link));
	p->n=num;
	p->nt=NULL;	
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		h=head;
		while(h->nt!=NULL)
		{
			h=h->nt;
		}
		h->nt=p;
	}
	return head;
}
struct link* pushfront(int num,struct link *head)
{
	struct link *p;	

	if(head==NULL)
	{
		p=push(num,head);
	}
	else
	{
		p=(struct link*)malloc(sizeof(struct link));
		p->n=num;
		p->nt=head;
	}
	return p;
}
void main()
{
	struct link *head;
	head=NULL;
	int f=0,ch,num;
	while(f==0)
	{
		printf("enter 1 for push,2 for push front ,3 pop ,4 popfront ,  5 display,7 sort, 6 to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter number");
				scanf("%d",&num);
				head=push(num,head);
				break;
			case 2:
				printf("enter number");
				scanf("%d",&num);
				head=pushfront(num,head);
				break;
			case 3:
				head=pop(head);
				break;
			case 4:
				head=popfront(head);
				break;
			case 5:
				display(head);
				break;
			case 7:
				sort(head);
				break;
			case 6:
				f=1;
				break;
		}
	}
}
