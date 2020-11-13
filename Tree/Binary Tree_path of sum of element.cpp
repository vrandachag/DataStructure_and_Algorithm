#include <iostream>
using namespace std;
void heapify(int arr[20],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        if(2*i+1<n)
        {
            if(arr[i]<arr[2*i+1])
            {
                temp=arr[i];
                arr[i]=arr[2*i+1];
                arr[2*i+1]=temp;
            }
            if(arr[i]<arr[2*i+2])
            {
                temp=arr[i];
                arr[i]=arr[2*i+2];
                arr[2*i+2]=temp;
            }
        }
    }
    cout<<"\nArray:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<arr[i];
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
    return 0;
}
