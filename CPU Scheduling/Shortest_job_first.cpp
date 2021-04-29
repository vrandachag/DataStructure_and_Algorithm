#include<algorithm>
#include <iomanip>
#include <ios>
#include<iostream>
#include<vector>
using namespace std;

bool check_not_in(vector<int>complete,int n)
{
	for(int i = 0 ;i<complete.size();i++)
	{
		if(complete[i] == n)
			return 0;
	}
	return 1;
}

void Sort(	int arr_time[10],int BT[10],int process,vector<int>&complete)
{
	int cpu_time = 0;
	int i = 0;
	while(complete.size() < process && i < process)
	{
		if(check_not_in(complete,i))
		{
			if(arr_time[i] <= cpu_time)
			{
				complete.push_back(i);
				cpu_time += BT[i];
				i = 0;
			}
			else
			{
				if(i+1 < process)
					i++;
				else
					i = 0;
			}
				
		}
		else
		{
			if(i+1 < process)
				i++;
			else
				i = 0;
		}
	}
}

void Sort_BT(vector<int>&complete,int arr_time[],int BT[])
{
	for(int i = 0 ; i < complete.size()-1 ; i++)
	{
		if((arr_time[complete[i]]!=0) && (BT[complete[i]]>BT[complete[i+1]]))
		{
			int temp = complete[i];
			complete[i] = complete[i+1];
			complete[i+1] = temp;
		}
	}
}

int main()
{
	int arr_time[10],BT[10],process,cpu_time = 0,CT[10],TAT[10],WT[10];
	float avg_tat = 0 , avg_wt = 0;
	vector<int>complete;
	cout<<"\nEnter number of processes:";
	cin>>process;
	for(int i = 0 ; i < process ; i++)
	{
		cout<<"\nEnter Arrival Time:";
		cin>>arr_time[i];
		cout<<"\nEnter Burst Time:";
		cin>>BT[i];
	}
	Sort(arr_time,BT,process,complete);

	Sort_BT(complete, arr_time, BT);

	for(int i = 0 ; i < complete.size() ; i++)
	{
		CT[complete[i]] = cpu_time + BT[complete[i]];
		cpu_time += BT[complete[i]];
		TAT[complete[i]] = CT[complete[i]] - arr_time[complete[i]];
		avg_tat += TAT[complete[i]];
		WT[complete[i]] = TAT[complete[i]] - BT[complete[i]];
		avg_wt += WT[complete[i]];
	}

		cout<<setw(7)<<"Process"<<setw(5)<<"AT"<<setw(5)<<"BT"<<setw(5)<<"CT"<<setw(5)<<"TAT"<<setw(5)<<"WT";

	for(int i=0;i<process;i++)
	{
		cout<<"\n"<<setw(7)<<complete[i]<<setw(5)<<arr_time[complete[i]]<<setw(5)<<BT[complete[i]]<<setw(5)<<CT[complete[i]]<<setw(5)<<TAT[complete[i]]<<setw(5)<<WT[complete[i]];
		
	}
	return 0;
}
