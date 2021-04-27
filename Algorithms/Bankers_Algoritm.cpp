#include<iostream>
#include<vector>
using namespace std;

bool check_performed(int no,vector<int>&performed)
{
	for(int i = 0 ; i < performed.size() ; i++)
	{
		if(performed[i] == no)
			return 1;
	}
	return 0;
}

void Bankers_Algo(	vector< vector<int> >allotted,	vector< vector<int> >need,vector<int>&available,vector<int>&performed)
{
	while(performed.size() < allotted.size() )
	{
		for(int i = 0 ; i < need.size() ; i++)
		{
			int flag = 0;
			if(!check_performed(i,performed))
			{
				for(int j = 0 ; j < available.size() ; j++)
				{
					if(need[i][j]>available[j])
					{
						flag = -1;
						break;
					}
				}
				
				if(flag == 0)
				{
						performed.push_back(i);
						for(int k = 0;k<available.size();k++)
						{
							available[k] += allotted[i][k];
						}
				}
			}
		}
	}
}

int main()
{
	vector< vector<int> >allotted, max_res,need;
	vector<int>available,performed;
	int n,res,ele;
	cout<<"\nEnter number of processes:";
	cin>>n;
	cout<<"\nEnter number of resources:";
	cin>>res;
	cout<<"\nEnter allotted array:\n";
	for(int i = 0 ; i < n ; i++)
	{
		vector<int>temp;
		for(int j = 0 ; j < res ; j++)
		{
			cin>>ele;
			temp.push_back(ele);
		}
		allotted.push_back(temp);
	}

	cout<<"\nEnter max array:\n";
	for(int i = 0 ; i < n ; i++)
	{
		vector<int>temp;
		for(int j = 0 ; j < res ; j++)
		{
			cin>>ele;
			temp.push_back(ele);
		}
		max_res.push_back(temp);
	}

	cout<<"\nEnter available resources:";
	for(int i = 0 ; i < res ; i++)
	{
		cin>>ele;
		available.push_back(ele);
	}

	for(int i = 0 ; i<n;i++)
	{
		vector<int>temp;
		for(int j = 0 ; j <res ; j++)
		{
			ele = max_res[i][j] - allotted[i][j];
			temp.push_back(ele);
		}
		need.push_back(temp);
	}

	Bankers_Algo(allotted,need,available,performed);

	for(int i = 0 ; i< performed.size();i++)
	{
		cout<<performed[i]<<"\t";
	}
}
