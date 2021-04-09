#include <bits/stdc++.h>
#include<vector>
using namespace std;

/*
int check(vector<int>arr,int x,int y)
{
	if(arr[x] == arr[y])
		return 1;
	else
		return 0;
}
*/

int patterns(vector<int>arr,vector<int>&mult,int k,int sum_arr = INT_MAX)
{
	int init_x = mult[0],init_y = mult[1],sum = 0,i;

	for(i = mult[1] ; i < arr.size()-1 ; i++)
	{
		if(arr[i] == arr[mult[1]])
		{
			sum = sum + (arr[mult[0]]*arr[mult[1]]*arr[i+1]);
			mult[1] = i+1;
		}
		else
			return -1;
	}

	if(i==arr.size()-1)
	{
		if(init_x > 0 || init_y > 1)
		{
			for(i = init_y ; i>0 ; i--)
			{
				if(arr[i] == arr[mult[1]])
				{
					sum = sum + (arr[mult[0]]*arr[mult[1]]*arr[i]);
					mult[1] = i;
					}
			}
		}
		else
			return -1;

		if(sum < sum_arr)
			sum_arr = sum;
	}









	for(int i = 0,j = 1 ; (i < arr.size()) && (j < arr.size() ); i++,j++)
	{
		int val = check(arr,i+1,j);
		if(val == 1)
		{
			s1 = s1 + (arr[i]*arr[i+1]*arr[j+1]);

		}
	}
}

int main()
{
	vector<int>arr,mult;
	int ele,n;
	mult.push_back(0);
	mult.push_back(1);
	for(int i = 0 ; i < n ; i++)
	{
		cin>>ele;
		arr.push_back(ele);
	}
	return 0;
}
