//graph
#include <iostream>
#include<map>
#include<vector>
using namespace std;

vector<vector<char> >dijkstra_arr;
map<char,int>m1;
vector<int>vect_not_taken;

void vect_push(int i, int j)
{
    char ch = 'A';
    vector<char>temp;
    temp.push_back(ch+i);
    temp.push_back(ch+j);
    dijkstra_arr.push_back(temp);
}

int check_map(int i)
{
    char ch = 'A';
    map <char,int> :: iterator it;
    for(it = m1.begin();it != m1.end();it++)
    {
        if(it->first == (ch+i))
            return it->second;
    }
    
    return -1;
}

void Dijkstra_algo(vector<vector<int> > graph,int sum = 0)
{
	cout<<"\nDijkstra_algo";
	int min,flag_j;
	char ch='A';
	m1[ch]=0;
	vect_push(0,0);
	cout<<"\nFirst node:";
	for(int i= 1 ; i<graph.size() ; i++)
	{
		min = 500;
		flag_j = 0;
		for(int j = 0; j < graph[i].size() ; j++)
		{
			if(graph[j][i] < min && graph[j][i] != 0)
			{
			    int check = check_map(j);
			    if(check == -1)
			        vect_not_taken.push_back(i);
			    else                             //if(check >= 0)
			    {
			        if(graph[j][i] + check < min)
			        {
    			        min = graph[j][i] + check;
    			    	flag_j = j;
			        }
			    }
			}
		}
		vect_push(flag_j,i);
		m1[ch+i] = min;
	}
	
	for(int i = 0 ; i < vect_not_taken.size() ; i++)
	{
	    int min = 500;
	    int idx = vect_not_taken[i];
	    for(int j = 0;j<graph.size(); j++)
	    {
			if(graph[j][idx] < min && graph[j][idx] != 0)
			{
			    int check = check_map(j);
			    if(check == -1)
			        vect_not_taken.push_back(idx);
			    else                             //if(check >= 0)
			    {
			        if(graph[j][idx] + check < min)
			        {
    			        min = graph[j][idx] + check;
    			    	flag_j = j;
			        }
			    }
			}
	    }
	    vect_push(flag_j,idx);
	    m1[ch+flag_j] = min;
	}
}

int main()
{
	vector<vector<int> > graph;
	int n,ele;
	cout<<"\nEnter number of keys:";
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		vector<int>arr;
		cout<<"\nEnter vector:";

		for(int j = 0;j<n;j++)
		{
			cin>>ele;
			arr.push_back(ele);
		}
		graph.push_back(arr);
	}
	Dijkstra_algo(graph);
	
	for(int i = 0; i<dijkstra_arr.size() ; i++)
	{
	    cout<<"\n"<<dijkstra_arr[i][0]<<" "<<dijkstra_arr[i][1];
	}
	return 0;
}
