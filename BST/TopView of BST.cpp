#include<iostream>
using namespace std;

struct BST
{
	int a,count=0;
	BST *left=NULL;
	BST *right=NULL;
};

int max=-1,min=1;

int TopView_of_BST(node *ptr,int count=0)
{
	ptr->count=count;
	if(ptr->left!=NULL)
	{
		if(count-1<min)
			min=count-1;
		TopView_of_BST(ptr->left,count-1);
	}
	if(ptr->right!=NULL)
	{
		if(count+1>max)
			max=count+1;
		TopView_of_BST(ptr->right,count+1);
	}
}

void Print_TopView(BST *ptr,int i=0)
{
	if(i<0 && i>=min)	
	{
		if(ptr->count==i)
		{
			cout<<"\na:"<<ptr->a<<"\tcount:"<<ptr->count;
			i--;
		}
	}
	else if(i<=max)
	{
		if(ptr->count==i)
		{
			cout<<"\na:"<<ptr->a<<"\tcount:"<<ptr->count;
			i++;
		}
	}
	if(ptr->left!=NULL)
		Print_TopView(ptr->left,i);
	if(ptr->right!=NULL)
		Print_TopView(ptr->right,i);
}

int main()
{
	return 0;
}
