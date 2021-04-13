#include <bits/stdc++.h>
#include<vector>
using namespace std;

int matrix_mult(int arr[10][10], vector<int>arr_ele, int x,int y)
{
	int s1=INT_MAX,s2 = INT_MAX;
  if(x==y)
		return 0;
	else
	{
		  if(x != (y-1))
		   {    
		    s1 = matrix_mult(arr, arr_ele, x, y-1);
		    if(y+1 < arr_ele.size())
    		    s1 = s1 + (arr_ele[x]*arr_ele[y]*arr_ele[y+1]);
        }
		   if(y+1 < arr_ele.size())
		  {
		    s2 = matrix_mult(arr, arr_ele, x+1, y);
		    s2+= (arr_ele[x]*arr_ele[x+1]*arr_ele[y+1]);
        }
		   if(s1<s2)
	    	{
			    if(arr[x][y] == 0 || arr[x][y] > s1)
				      arr[x][y] = s1;                 
		    }
		   else
	   	 {
    			if(arr[x][y] == 0 || arr[x][y] > s2)
		     		arr[x][y] = s2;
		   }
	}
	return arr[x][y];
}


int main()
{
	vector<int>arr_ele;
	int ele,n,arr[10][10] = {0};
	cout<<"\nEnter number of elements:";
	cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		cin>>ele;
		arr_ele.push_back(ele);
	}
	int answer1 = matrix_mult(arr,arr_ele,0,n-1);
/*	for(int i = 0;i<=n;i++)
	{
		cout<<"\n";
		for(int j =0;j<=n;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
	}*/
	cout<<"\nAnswer:"<<answer1;
	return 0;
}
