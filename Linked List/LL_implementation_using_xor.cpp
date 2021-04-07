#include<iostream>
using namespace std;

struct node
{
	int n;
	node *next;
};

node *start = NULL;

node *Insert(node *ret_ptr = NULL)
{
    if(start == NULL)
    {
        start = new node;
        cout<<"\nEnter value:";
        cin>>start->n;
        start->next = NULL;
				return start;
    }
    else
    {
			cout<<"\nelse";
			node *p = ret_ptr,*p2 = NULL;
//			node *k =(struct node*)((uintptr_t)p->next xor (uintptr_t)p);
			p2 = new node;
			cout<<"\nEnter value:";
			cin>>p2->n;
			node *k=(struct node*)((uintptr_t)(p->next) xor (uintptr_t)p2);
			p->next = k;
			p2->next = p;
			cout<<"\np->next"<<p->next<<"\tp2->next"<<p2->next;
			return p2;
    }
}

void Display_front(node *ptr = start)
{
	node *k = NULL,*ptr1 = ptr;
	while(ptr1 != NULL)
	{
		cout<<"\n"<<ptr1->n;
		ptr = (struct node*)((uintptr_t)ptr->next xor (uintptr_t)k);
		k = ptr1;
		ptr1 = ptr;
	}

	cout<<"\nbackward:";
	ptr1 = k;
	k = NULL;
	while(ptr1 != NULL)
	{
		cout<<"\n"<<ptr1->n;
		ptr = (struct node*)((uintptr_t)ptr1->next xor (uintptr_t)k);		
		k = ptr1;
		ptr1 = ptr;
	}

}
int main()
{
	char ch = 'Y';
	node *p = NULL;
	while(ch == 'Y' || ch == 'y')
	{
		p = Insert(p);
		cout<<"\nWant to enter more?";
		cin>>ch;
	}
	Display_front();
  return 0;
}
