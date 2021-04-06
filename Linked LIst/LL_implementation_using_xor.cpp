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
        node *p = start,*p2 = NULL;
        while(p->next != p)
        {
            p = p->next;
        }
        p2 = new node;
        cout<<"\nEnter value:";
        cin>>p2->n;
		p2->next=(struct node*)((uintptr_t)p xor (uintptr_t)p2);
		cout<<p2->next;
    }
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
  return 0;
}
