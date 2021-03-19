//graph
#include <iostream>
#include<vector>
using namespace std;

struct tree
{
	char ch;
	tree *left = NULL,*right = NULL;
};

tree *start_tree = NULL;

/*rec function
void make_arr_tree(int i, int j, tree *a1 = start_tree)
{
	char ch = 'A';
	if(start_tree == NULL)
	{
		start_tree = new tree;
		start_tree->ch = ch+i;
		start_tree->left = NULL;
		start_tree->right = NULL;
	}
	else
	{

	}
}
*/
void make_arr_tree(int i,int j)
{
	tree *a1 = start_tree;
	char ch = 'A';
	if(start_tree == NULL)
	{
		start_tree = new tree;
		start_tree->ch = ch+i;
		cout<<"\nstart:"<<start_tree->ch;
		start_tree->left = NULL;
		start_tree->right = NULL;
    cout<<"Hello"; 
		return;
	}
	
	else
	{
		while(a1 != NULL)
		{
			if(a1->ch == (ch+i))
			{
				if(a1->left == NULL)
				{
					a1->left = new tree;
					a1->left->ch = (ch+j);
					a1->left->left = NULL;
					a1->left->right = NULL;
					break;
				}
			}
			else if(a1->left != NULL)
			{
				if(a1->left->ch == (ch+i))
				{
					a1 = a1->left;
					if(a1->left == NULL)
					{
						a1->left = new tree;
						a1->left->ch = (ch+j);
						a1->left->left = NULL;
						a1->left->right = NULL;
						break;
					}
					else if(a1->right == NULL)
					{
						a1->right = new tree;
						a1->right->ch = (ch+j);
						a1->right->left = NULL;
						a1->right->right = NULL;
						break;
					}
				}
				else if(a1->right->ch == (ch+i))
				{
					a1 = a1->right;
					if(a1->left == NULL)
					{
						a1->left = new tree;
						a1->left->ch = (ch+j);
						a1->left->left = NULL;
						a1->left->right = NULL;
						break;
					}
					else if(a1->right == NULL)
					{
						a1->right = new tree;
						a1->right->ch = (ch+j);
						a1->right->left = NULL;
						a1->right->right = NULL;
						break;
					}

				}
			}
			if(a1->left != NULL)
				a1 = a1->left;
		}
	}*/
}

void Display(tree *ptr = start_tree)
{
	if(ptr == NULL)
		return;
	else
	{
		cout<<"\n"<<ptr->ch;
		if(ptr->left != NULL)
			cout<<"\tleft:"<<ptr->left->ch;
		if(ptr->right != NULL)
			cout<<"\nright:"<<ptr->right->ch;
		if(ptr->left != NULL)
			Display(ptr->left);
		if(ptr->right != NULL)
			Display(ptr->right);
	}
}

void Prims_algo(vector<vector<int> > graph)
{
	cout<<"\nPrims_algo";
	int min,flag_j;
	make_arr_tree(0,0);
	cout<<"\nFirst node:";
	for(int i= 1 ; i<graph.size() ; i++)
	{
		min = 500;
		flag_j = 0;
		for(int j = 0; j< graph[i].size();j++)
		{
			if(graph[j][i] < min && graph[j][i] != 0)
			{
				min = graph[j][i];
				flag_j = j;
			}
		}
		make_arr_tree(i,flag_j);
	}
}

int main()
{
	vector<vector<int> > graph;
	int n,ele;
	cout<<"\nEnter number of keys:";
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		vector<int>arr;
		cout<<"\nEnter vector:";

		for(int j = 0;j<n;j++)
		{
			cin>>ele;
			arr.push_back(ele);
		}
		graph.push_back(arr);
	}
	Prims_algo(graph);
	Display();
	return 0;
}
/*
void make_tree(int i,int j)
{
	tree * ptr = start_tree;
	if(start_tree == NULL)
	{
		start_tree->ch = 65+i;
		start_tree->left->ch = 65+j;
		start_tree->left->left = NULL;
		start_tree->left->right = NULL;
		start_tree->right = NULL;
	}
	else
	{

		if(ptr->ch == 65+i)
		{

		}	
		else
		{
			if(ptr->left!=NULL)
				ptr=ptr->left;
			else if(ptr->right != NULL)
				ptr=ptr->right;
		}
	}
}
*/
