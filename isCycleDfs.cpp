//Detect loop in the graph is performed by dfs approach.In this we also store parent to keep track.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool findCycleDfs(vector<int> adj[],int src,int parent,int vis[])
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                if(findCycleDfs(adj,it,src,vis)==true)
                   return true;
            }
            else if(parent!=it)
            {
                return true;
            }
        }
        return false;
        
    }
    public:
    bool findCycle(vector<int> adj[],int V)
    {
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(findCycleDfs(adj,i,-1,vis)==true)
                  return true;
            }
        }
        return false;
    }
    
};

int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.findCycle(adj,4);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}
