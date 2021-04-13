#include <bits/stdc++.h>
#include<map>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	string s1;
	map<string, int>::iterator it;
	map<string,int> suffix_arr;
	cout<<"\nEnter string:";
	cin>>s1;
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

	cout<<"\n\n";
	for(it = suffix_arr.begin() ; it!=suffix_arr.end();it++ )
	{
		cout<<"\t"<<it->second;
	}
	return 0;
}
