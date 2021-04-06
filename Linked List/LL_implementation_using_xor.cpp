#include<iostream>
using namespace std;

struct node
{
	int n;
	node *next;
};

node *start = NULL;

void Insert()
{
    if(start == NULL)
    {
        start = new node;
        cout<<"\nEnter value:";
        cin>>start->n;
        start->next = start;
    }
    else
    {
			cout<<"\nelse";
			node *p = start,*p2 = NULL;
			cout<<"\nstart:"<<start;
			node *k =(struct node*)((uintptr_t)p->next xor (uintptr_t)p);
			while( k != NULL)
			{
				  p = k;
					k = (struct node*)((uintptr_t)p->next xor (uintptr_t)p);
			}
			p2 = new node;
			cout<<"\nEnter value:";
			cin>>p2->n;
			p->next=(struct node*)((uintptr_t)p xor (uintptr_t)p2);
			p2->next = p;
			cout<<"\np->next"<<p->next<<"\tp2->next"<<p2->next;
    }
}

void Display(node *ptr = start)
{
	node *k =(struct node*)((uintptr_t)ptr->next xor (uintptr_t)ptr);
	while(k != NULL)
	{
		cout<<"\n"<<ptr->n;
		ptr = k;
		k = (struct node*)((uintptr_t)ptr->next xor (uintptr_t)ptr);

	}
//	cout<<"\n"<<ptr->n;
}
int main()
{
	char ch = 'Y';
	while(ch == 'Y' || ch == 'y')
	{
		Insert();
		cout<<"\nWant to enter more?";
		cin>>ch;
	}
	Display();
  return 0;
}
