/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include<stdio.h>
 #include<stdlib.h>
 struct ListNode {
      int val;
      struct ListNode *next;
 };
 struct ListNode* insert(struct ListNode* head,int n){
    struct ListNode *p,*e;
    p=head;
    e=(struct ListNode *)malloc(sizeof(struct ListNode));
    e->val=n;
    e->next=NULL;
    if(head==NULL)
    {
        head=e;
        return head;
    }
    while(p->next!=NULL)
       p=p->next;
    p->next=e;
    return head;
 }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *h,*hh,*p=NULL;
    h=l1;
    hh=l2;
    int c=0,s=0;
    while(h!=NULL && hh!=NULL)
    {
        s=h->val+hh->val+c;
        if(s>9)
        {
            s=s%10;
            c=1;
        }
        else 
            c=0;

        p=insert(p,s);

        h=h->next;
        hh=hh->next;
    }
    while(h!=NULL)
    {
        s=h->val+c;
        if(s>9)
        {
            s=s%10;
            c=1;
        }
        else
            c=0;
        p=insert(p,s);
        h=h->next;
    }
    while(hh!=NULL)
    {
        s=hh->val+c;
        if(s>9)
        {
            s=s%10;
            c=1;
        }
        else
            c=0;
        p=insert(p,s);
        hh=hh->next;
    }
    if(c==1)
        insert(p,1);
    return p;
}
void main()
{
	struct ListNode *l1,*l2,*s;
	l1=NULL;
	l2=NULL;
	s=NULL;
	int n,m;
	printf("enter num1 ");
	scanf("%d",&n);
	printf("enter num2 ");
	scanf("%d",&m);
	while(n!=0)
	{
		l1=insert(l1,n%10);
		n/=10;
	}
	while(m!=0)
	{
		l2=insert(l2,m%10);
		m/=10;
	}
	s=addTwoNumbers(l1,l2);
	while(s!=NULL)
	{
		printf("%d ",s->val);
		s=s->next;
	}
}
