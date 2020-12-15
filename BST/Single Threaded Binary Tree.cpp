#include<iostream>
#include<vector>
using namespace std;

struct Threaded_BT
{
	int a;
	bool flag-0;
	Threaded_BT *left=NULL,*right=NULL;
};
Threaded_BT *start=NULL;

BST *arr_to_BST(vector<int>arr,int beg,int end)
{
	BST *ptr;
	
	if(beg<=end)
	{
		ptr=new BST;
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->a=arr[(beg+end)/2];
		int mid=(beg+end)/2;
		ptr->left=arr_to_BST(arr,beg,mid-1);
		ptr->right=arr_to_BST(arr,mid+1,end);	
		return ptr;
	}
	else
		return NULL;
}

int main()
{
	int n;
	vector<int>arr;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter number:";
		cin>>arr[i];
	}
	
	return 0;
}
