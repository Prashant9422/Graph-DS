//Detect loop in the graph is performed by bfs approach.In this we also store parent. q.push({node,parent}) to keep track.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool findCycleBfs(vector<int> adj[],int src,int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent)
                {
                    return true;
                }
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
                if(findCycleBfs(adj,i,vis)==true)
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
