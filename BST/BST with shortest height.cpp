#include<iostream>
#include<vector>
using namespace std;

struct BST
{
	int a;
	BST *left=NULL;
	BST *right=NULL;
};

BST *start=NULL;

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
void Display_BST(BST *ptr=start)
{
	if(ptr == NULL)
		return;
	Display_BST(ptr->left);
	cout<<"\t"<<ptr->a;
	Display_BST(ptr->right);
}

int main()
{
	vector<int>arr;
	int n,a1;
	cout<<"\nEnter number of elements:";
	cin>>n;
	cout<<"\nEnter sorted array:";
	for(int i=0;i<n;i++)
	{
		cin>>a1;
		arr.push_back(a1);
	}
	/*start=new BST;
	start->a=arr[n/2];
	cout<<"\nStart initialized";
	cout<<"\n"<<start->a;
	start->left=arr_to_BST(arr,0,n/2);
	start->right=arr_to_BST(arr,n/2+1,n-1);*/
	start=arr_to_BST(arr,0,n-1);
	Display_BST();
	return 0;
}
