#include<iostream>
#include<conio.h>
using namespace std;

void Bsearch(int a[],int s,int e, int num)
{
	int mid = (s+e)/2;
  if(s <= e)	
  {
		if(a[mid] < num)
	{
		Bsearch(a,0,mid,num);
	}
	
	else if(a[mid] == num)
	{
		cout<<"Element found";
	}
	
	else
	{
		Bsearch(a,mid,e,num);
	}
 } 
 
 else
 	cout<<"\nElement not found";
}
int main()
{
	int a[10], n,num;
	
	cout<<"\nEnter size of array:";
	cin>>n;
	
	for(int i = 0; i<n ; i++)
	{
		cout<<"Enter "<<i+1<<"element:";
		cin>>a[i];
	}
	
	cout<<"Enter number to be searched:";
	cin>>num;
	
	Bsearch(a,0,n,num);

	return 0;
}

