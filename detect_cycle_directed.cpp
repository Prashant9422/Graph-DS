//Detection of loop in directed graph
//Two array is used-vis,distVis
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool isCycleDfs(vector<int> adj[],int vis[],int distVis[],int src)
    {
        vis[src]=1;
        distVis[src]=1;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
               if(isCycleDfs(adj,vis,distVis,it)==true)
                  return true;
            }
            else if(vis[it])
            {
                return true;
            }
           
        }
        distVis[src]=0;
        return false;
        
    }
    public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V]={0};
        int distVis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(isCycleDfs(adj,vis,distVis,i)==true)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
   vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
