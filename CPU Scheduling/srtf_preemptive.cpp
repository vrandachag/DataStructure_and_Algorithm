#include<algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include<iostream>
#include<vector>
using namespace std;

int smallest(int BT[],vector<int>arr)
{
	int small = BT[arr[0]],flag = arr[0];
	for(int i = 1 ; i<arr.size() ; i++)
	{
		if(small > BT[arr[i]])
		{
			small = BT[arr[i]];
			flag = arr[i];
		}
	}
	return flag;
}

bool check_not_in(vector<int>arr,int n)
{
	for(int i = 0 ;i<arr.size();i++)
	{
		if(arr[i] == n)
			return 0;
	}
	return 1;
}

int main()
{
	int arr_time[10],BT[10],process,cpu_time = 0,CT[10],TAT[10],WT[10] = {0};
	float avg_tat = 0 , avg_wt = 0;
	vector<int>complete,BT_copy;
	cout<<"\nEnter number of processes:";
	cin>>process;
	for(int i = 0 ; i < process ; i++)
	{
		cout<<"\nEnter Arrival Time:";
		cin>>arr_time[i];
		cout<<"\nEnter Burst Time:";
		cin>>BT[i];
		BT_copy.push_back(BT[i]);
	}

	while(complete.size() < process)
	{
		label:
		vector<int>temp;
		for(int i = 0 ; i < process ; i++)
		{
			if(check_not_in(complete, i))
			{
				if(arr_time[i]<=cpu_time)
				{
					temp.push_back(i);
				}
			}
		}

		if(temp.size() == 0)
		{
			cpu_time++;
			goto label;
		}
		int idx = smallest(BT,temp);
		if(WT[idx] == 0)
		{
			WT[idx] = cpu_time - arr_time[idx];
			avg_wt += WT[idx];
		}

		CT[idx] = ++cpu_time;
		BT[idx]--;
		if(BT[idx] == 0)
			complete.push_back(idx);
		if(WT[idx] == 0)
		{
		}
	}

		for(int idx = 0 ; idx < process;idx++)
		{
			WT[idx] = CT[idx]- arr_time[idx]-BT_copy[idx];
			avg_wt += WT[idx];

			TAT[idx] = WT[idx] + BT_copy[idx];
			avg_tat += TAT[idx];
		}

		cout<<setw(7)<<"\nProcess"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT";

	for(int i=0;i<process;i++)
	{
		cout<<"\n"<<setw(7)<<complete[i]<<setw(5)<<arr_time[complete[i]]<<setw(5)<<BT_copy[complete[i]]<<setw(5)<<CT[complete[i]]<<setw(5)<<TAT[complete[i]]<<setw(5)<<WT[complete[i]];
		
	}

	cout<<"\nAverage TAT:"<<(avg_tat/process);
	cout<<"\nAverage WT:"<<(avg_wt/process);

	return 0;
}

