//Task is to assign color to node but adjacent node should have different color.
//If any graph does not contain any closed path then it is always a biparatite graph.
//If any graph contain cycle then if it is even the it is always possible the color but if it is odd then it is impossible to assign 
//differnet color
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool isBipartiteBfs(vector<int> adj[],int color[],int start,int V)
    {
        
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[node]==color[it])
                {
                    return false;
                }
                
            }
        }
        return true;
        
    }
    public:
    bool isBipartite(int V,vector<int> adj[])
    {
        int color[V]={-1};
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
               if(isBipartiteBfs(adj,color,i,V)==true)
               {
                  return true;
               }
            }
        }
        return false;
    }
};
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    // V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}
