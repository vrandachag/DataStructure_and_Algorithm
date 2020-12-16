#include<iostream>
#include<vector>
using namespace std;

void Insertion_Sort(float arr[10][10],int n,int idx)
{
	for(int i=0;i<n;i++)
	{	int k=i;
		float temp=arr[idx][i];
		while(k-1>=0 && arr[idx][k] < arr[idx][k-1])
		{
			arr[idx][k]=arr[idx][k-1];
			k=k-1;
		}

		arr[idx][k]=temp;
	}
}

void Bucket_Sort(float arr[20],int n)
{
	float temp[10][10];
	int count[10]={0};	
	for(int i=0;i<n;i++)
	{
		int idx = arr[i]*10;
		temp[idx][count[idx]]=arr[i];
		count[idx]++;
	}

	for(int i=0;i<10;i++)
	{
		if(count[i]>0)
		{
			Insertion_Sort(temp,count[i],i);
		}
	}


	int i=0;
	for(int j=0;j<10 && i<n;j++)
	{
		if(count[j]>0)
		{
			for(int k=0;k<count[j];k++)
			{
				arr[i]=temp[j][k];
				i++;
			}
		}
	}
}

int main()
{
	int n;
	float arr[20];
	cout<<"\nEnter number of elements:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter number:";
		cin>>arr[i];
	}
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];
	}
	Bucket_Sort(arr, n);

	cout<<"\nSorted array:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];
	}
	return 0;
}