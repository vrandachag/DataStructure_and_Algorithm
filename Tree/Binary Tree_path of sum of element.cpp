#include <iostream>
#include<vector>
using namespace std;

void check(Tree *ptr,vector<int>arr,int n,int sum=0)
{
    if(sum<n)
    {
        if((sum+ptr->a)<=n)
        {
            sum=sum+ptr->a;
            arr.push_back(ptr->a);
        }
        else if(ptr->a==n)
        {
            cout<<"\nPath possible\n"<<ptr->a;
            return;
        }
        
        {
            if(ptr->right!=NULL)
                check(ptr->right,arr,n,sum);
            if(ptr->left!=NULL)
                check(ptr->left,arr,n,sum);
        }    
    }
}

int main()
{
    vector<int>arr;
    return 0;
}
