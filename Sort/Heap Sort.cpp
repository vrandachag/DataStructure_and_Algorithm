#include <iostream>
using namespace std;

void arrange(int arr[20],int n);

void heapify(int arr[20],int n)
{
    int temp;
    for(int i=n/2;i>=0;i--)
    {
        if((2*i)+1<n)
        {
            if(arr[i]<arr[(2*i)+1])
            {
                temp=arr[i];
                arr[i]=arr[(2*i)+1];
                arr[(2*i)+1]=temp;
            }
        }
        
        if((2*i)+2<n)
            if(arr[i]<arr[(2*i)+2])
            {
                temp=arr[i];
                arr[i]=arr[(2*i)+2];
                arr[(2*i)+2]=temp;
            }
    }
    
    {	
	    cout<<"\nSorted Array:\n";
	    for(int i=0;i<n;i++)
	    {
	        cout<<"\t"<<arr[i];
	    }
	}
    arrange(arr,n);
}

void arrange(int arr[20],int n)
{
	int temp;
	if(n>1)
	{
		temp=arr[0];
		arr[0]=arr[n-1];
		arr[n-1]=temp;
		cout<<"\nlast element:"<<arr[n-1];
		heapify(arr,n-1);
	}
	
}
int main()
{
    int arr[20],n;
    cout<<"\nEnter number of elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter element:";
        cin>>arr[i];
    }
    heapify(arr,n);  
	 
	{	
	    cout<<"\nSorted Array:\n";
	    for(int i=0;i<n;i++)
	    {
	        cout<<"\t"<<arr[i];
	    }
	}
	return 0;
}
