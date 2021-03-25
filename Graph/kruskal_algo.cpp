#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;


char check_parent(char ch, vector<char>parent)
{
    while(ch != parent[ch-65])
    {
        ch = parent[ch-65];
    }
    return ch;
}
void parent_init(vector<char>&parent, int n)
{
    char ch = 'A';
    for(int i = 0 ; i < n ; i++)
    {
        parent.push_back(ch + i);
    }
}

void kruskal_algo(vector<pair<int,pair<char, char> > > &g1,vector<char>parent,int rank[10],int n)
{
	int count = 0;
    for(int i = 0 ; i < g1.size() ; i++ )
    {
        char ch1 = check_parent(g1[i].second.first,parent);
        char ch2 = check_parent(g1[i].second.second,parent);

        if(ch1 != ch2)
        {
						count++;
            cout<<"\n"<<g1[i].second.first<<"\t"<<g1[i].second.second;
            if(rank[ch1-65] <= rank[ch2-65])
            {
                parent[ch1-65] = ch2;
                rank[ch2-65]++;
            }
            else //if(rank[ch1-65] > rank[ch2-65])
            {
                parent[ch2-65] = ch1;
                rank[ch1-65]++;
            }
        }

				if(count == (n-1))
					break;
    }
}


int main()
{
    int rank[10] = {0};
    vector<char>parent;
    vector<pair<int,pair<char, char> > > g1;
    int n,edges;
    cout<<"\nEnter number of edges:";
    cin>>edges;
		cout<<"\nEnter number of nodes";
		cin>>n;
    for(int i = 0; i< edges;i++)
    {
        int arr;
        char ch1,ch2;
        cin>>arr>>ch1>>ch2;
        g1.push_back({arr,{ch1,ch2}});
    }

    sort(g1.begin(),g1.end());
    parent_init(parent,n);
    kruskal_algo(g1,parent,rank,n);
    return 0;
}
