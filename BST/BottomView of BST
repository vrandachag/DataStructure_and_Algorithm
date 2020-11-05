#include<iostream>
using namespace std;

int maximum=-1,minimum=1,BottomView[10];

int BottomView_of_BST(BST *ptr,int count=0)
{
	ptr->count=count;
	if(ptr->left!=NULL)
	{
		if(count-1<minimum)
			minimum=count-1;
		Bottom_of_BST(ptr->left,count-1);
	}
	if(ptr->right!=NULL)
	{
		if(count+1>maximum)
			maximum=count+1;
		Bottom_of_BST(ptr->right,count+1);
	}
}

void BV_arr_assign(BST *ptr=start,int add)
{
	if(ptr == NULL)
		return;
	BV_arr_assign(ptr->left,add);
	BottomView[ptr->count+add]=ptr->a;
	BV_arr_assign(ptr->right,add);
}

void Print_BottomView()
{
	for(int i=0;i<=maximum+(-(minimum));i++)
	{
		cout<<"\t"<<BottomView[i];	
	}	
}
int main()
{
	BottomView_of_BST(start);
	BV_arr_assign(start->left,-(minimum));
	BV_arr_assign(start->right,-(minimum));
	Print_BottomView();
	return 0;
}
