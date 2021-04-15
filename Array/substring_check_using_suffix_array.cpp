//program to check if substring exists in original string using suffix array
#include <bits/stdc++.h>
#include<map>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

void check_arr(vector<int>arr,string s1, char pattern[],int end ,int beg = 0 )
{
	if(beg>=end)
	{
		cout<<"\nPattern does not exist";
		return;
	}
	int mid = (beg + end)/2,i;
  char check1[20];
  s1.copy(check1,s1.length()-arr[mid],arr[mid] );
	check1[s1.length()-arr[mid]] = '\0';
	
	if(strcmp(check1, pattern) < 0)
		return check_arr(arr, s1, pattern, end,mid+1);
	else if(strcmp(check1, pattern) == 0)
	{
			cout<<"\nPattern exists";
			return;
	}
	else
		return check_arr(arr, s1, pattern, mid, beg);

}

int main()
{
	string s1;
	char check[20];
	int flag = -1;
	vector<int>arr;
	map<string, int>::iterator it;
	map<string,int> suffix_arr;
	cout<<"\nEnter string:";
	cin>>s1;
	cout<<"\nEnter pattern:";
	cin>>check;
	for(int i = s1.length() ; i > 0 ; i--)
	{
		string ch = "";
		int k = i-1;
		while(k < s1.length())
		{
			ch = ch + s1[k];
			k++;
		}
		suffix_arr[ch] = i-1;
	}

	for(it = suffix_arr.begin() ; it!=suffix_arr.end();it++ )
	{
		arr.push_back(it->second);
	}

	check_arr(arr,s1,check,s1.length());
	return 0;
}
