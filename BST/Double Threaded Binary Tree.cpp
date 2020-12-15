#include<iostream>
#include<vector>
using namespace std;

struct Threaded_BT
{
	int a;
	bool l_thread=0,right_thread=0;
	Threaded_BT *left=NULL,*right=NULL;
};
Threaded_BT *start=NULL;

Threaded_BT *arr_to_Threaded_BT(vector<int>arr,int beg,int end,Threaded_BT *inorder_left=NULL, Threaded_BT *inorder_right=NULL)
{
	Threaded_BT *ptr;

	if(beg<=end)
	{
		ptr=new Threaded_BT;
		if(start==NULL)
			start=ptr;
		ptr->left=inorder_left;
		ptr->right=inorder_right;
		ptr->a=arr[(beg+end)/2];
		int mid=(beg+end)/2;
		if(beg<=mid-1)
		{
			ptr->left=arr_to_Threaded_BT(arr,beg,mid-1,inorder_left,ptr);
			ptr->l_thread=0;
		}
		else
			ptr->l_thread=1;
		if(mid+1<=end)
		{
			ptr->right_thread=0;
			ptr->right=arr_to_Threaded_BT(arr,mid+1,end,ptr,inorder_right);
		}	
		else
			ptr->right_thread=1;
		return ptr;
	}
}

void Display(Threaded_BT *ptr=start)
{
	if(ptr == NULL)
		return;
	if(ptr->l_thread==0)
		Display(ptr->left);
	cout<<"\n"<<ptr->a;
	if(ptr->left!=NULL)
		cout<<"\tleft:"<<ptr->left->a;
	if(ptr->right!=NULL)
	{	//if(ptr->flag!=1)
		cout<<"\tright:"<<ptr->right->a;
	if(ptr->right_thread == 0)
		Display(ptr->right);
	}
}

int main()
{
	int n,ele;
	vector<int>arr;
	cout<<"\nEnter number of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter number:";
		cin>>ele;
		arr.push_back(ele);
	}
	arr_to_Threaded_BT(arr, 0, n-1);
	Display();
	return 0;
}
