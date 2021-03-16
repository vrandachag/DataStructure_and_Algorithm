//graph
#include <iostream>
#include<vector>
using namespace std;

struct node
{
	char ch;
	node *next = NULL;
};

struct key
{
	char ch1;
	key *ptr = NULL;
	node *next_ptr = NULL;
};

key *start_key = NULL;

node *new_node(node **pre )
{
	node *p2 = NULL;
	p2 = new node;
	cout<<"\nEnter value:";
	cin>>p2->ch;
	if((*pre) != NULL)
		(*pre)->next = p2;
	p2->next = NULL; 
	return p2;
}

void new_key(int n,key **pre_key = NULL)
{
	key *p1 = NULL;
	cout<<"\nNew key";
	if(n>0)
	{
		cout<<"\nif ";
		char choice;

		if(start_key == NULL)
		{
			start_key = new key;
			cout<<"\nEnter node value:";
			cin>>start_key->ch1;
			start_key->ptr = NULL;
			start_key->next_ptr = NULL;	
			p1 = start_key;
		}
		else
		{
		
			p1 = new key;
		  (*pre_key)->ptr = p1;	
			cout<<"\nEnter node value:";
			cin>>p1->ch1;
			p1->ptr = NULL;
			p1->next_ptr = NULL;
		}

		cout<<"\nWant to enter more?";
		cin>>choice;
		node *ret_ptr = p1->next_ptr;

		while(choice == 'Y' || choice == 'y')
		{
			ret_ptr = new_node(&ret_ptr);
			if(p1->next_ptr == NULL)
			{
				p1->next_ptr = ret_ptr;
			}
			cout<<"\nWant to enter more?";
			cin>>choice;
		}
		
		new_key(n-1,&p1);
	}
/*	else
	{
		cout<<"\nelse";
		pre_key->ptr = NULL;
	}*/
}

void Display(key *ptr_para = start_key)
{
	if(ptr_para == NULL)
		return;
	
	cout<<"\n"<<ptr_para->ch1<<":";
	if(ptr_para->next_ptr != NULL)
	{
		node *ptr2 = ptr_para->next_ptr;
		while(ptr2 != NULL)
		{
			cout<<ptr2->ch<<"\t";
			ptr2 = ptr2->next; 
		}
	}

	Display(ptr_para->ptr);
}

void BFS(key *bfs_ptr = start_key)
{
	if(bfs_ptr == NULL)
		return;
	else
	{
		cout<<bfs_ptr->ch1<<"\t";
		BFS(bfs_ptr->ptr);
	}
}

int in_vector(char ch, vector<char>DFS_vect)
{
	for(int i = 0;i<DFS_vect.size();i++)
	{
		if(DFS_vect[i] == ch)
			return 0;
	}

	return 1;
}

void DFS(vector<char>&DFS_vector, char ch,key *dfs_ptr_k = start_key)
{
	node *dfs_n_ptr = NULL;
	if(dfs_ptr_k != NULL)
	{
		if(dfs_ptr_k->ch1 == ch)
		{  
			if(in_vector(ch, DFS_vector))
			{
				DFS_vector.push_back(ch);
				dfs_n_ptr = dfs_ptr_k->next_ptr;
				if(dfs_n_ptr != NULL)
				{
					DFS(DFS_vector,dfs_n_ptr->ch);
					while(dfs_n_ptr->next != NULL)
					{
						DFS(DFS_vector,dfs_n_ptr->next->ch);
						dfs_n_ptr = dfs_n_ptr->next;
					}
				}
			}
		}
		else
		{
			DFS(DFS_vector,ch,dfs_ptr_k->ptr);
		}
	}
}

int main()
{
	int n;
	vector<char>DFS_vector;
	cout<<"\nEnter number of keys:";
	cin>>n;
	new_key(n);
	Display();
	cout<<"\nBFS: ";
	BFS();
	cout<<"\nDFS: ";
	DFS(DFS_vector,start_key->ch1);
	for(int i = 0 ; i < DFS_vector.size(); i++)
	{
		cout<<DFS_vector[i]<<"\t";
	}
	return 0;
}
