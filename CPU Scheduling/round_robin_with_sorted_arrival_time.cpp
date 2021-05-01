//round robin
#include<algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include<iostream>
#include<vector>
using namespace std;

bool check_not_in(vector<int>arr,int n)
{
	for(int i = 0 ;i<arr.size();i++)
	{
		if(arr[i] == n)
			return 0;
	}
	return 1;
}

void sort_arr(int arr_time[10],int process,vector<int>&sort_AT)
{
	while(sort_AT.size()<process)
	{
			int small = INT_MAX,flag = -1;

		for(int i = 0 ; i < process ; i++)
		{
			if(check_not_in(sort_AT, i))
			{
				if(small > arr_time[i])
				{
					small = arr_time[i];
					flag = i;
				}
			}
		}
		if(flag != -1)
			sort_AT.push_back(flag);
	}
}

int main()
{
	int arr_time[10],BT[10],process,cpu_time = 0,CT[10],TAT[10],WT[10] = {0},TQ;
	float avg_tat = 0 , avg_wt = 0;
	vector<int>complete,BT_copy,sort_ar;
	cout<<"\nEnter number of processes:";
	cin>>process;
	cout<<"\nEnter time quantum:";
	cin>>TQ;
	for(int i = 0 ; i < process ; i++)
	{
		cout<<"\nEnter Arrival Time:";
		cin>>arr_time[i];
		cout<<"\nEnter Burst Time:";
		cin>>BT[i];
		BT_copy.push_back(BT[i]);
	}

	sort_arr(arr_time, process, sort_ar);

	while(complete.size() < process)
	{
		for(int i = 0 ; i < process ; i++)
		{
			if(check_not_in(complete, sort_ar[i]))
			{
				if(arr_time[sort_ar[i]]<=cpu_time)
				{
					cout<<sort_ar[i]<<"\t";
					{
						int k = TQ;
						while(k > 0)
						{
							if(BT[sort_ar[i]]-1 >= 0)
							{
								BT[sort_ar[i]]--;
								cpu_time++;
							}
							else
								break;
							k--;
						}
					}
					if(BT[sort_ar[i]] == 0)
					{
						complete.push_back(sort_ar[i]);
						CT[sort_ar[i]] = cpu_time;
					}
				}
			}
		}
	}

		for(int idx = 0 ; idx < process;idx++)
		{
			TAT[idx] = CT[idx] - arr_time[idx];
			avg_tat += TAT[idx];

			WT[idx] = TAT[idx] - BT_copy[idx];
			avg_wt += WT[idx];

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
