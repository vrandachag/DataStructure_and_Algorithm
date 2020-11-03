//program consists of function which converts BST to Greater Sum Tree
#include<iostream>
using namespace std;

int BST_to_GST(BST *ptr,int sum=0)
{
	int temp=0;
	if(ptr!=NULL)
	{
		sum=BST_to_GST(ptr->right,sum);
		temp=ptr->a;
		ptr->a=sum;
		sum=BST_to_GST(ptr->left,sum+temp);
	}
	else
		return sum;	
}

int main()
{
  return 0;
}
