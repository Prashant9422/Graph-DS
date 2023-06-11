//Task is to assign color to node but adjacent node should have different color.
//If any graph does not contain any closed path then it is always a biparatite graph.
//If any graph contain cycle then if it is even the it is always possible the color but if it is odd then it is impossible to assign 
//differnet color
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool isBipartiteDfs(vector<int> adj[],int color[],int start,int col)
    {
        color[start]=0;
        for(auto it:adj[start])
        {
            if(color[it]==-1)
            {
                if(isBipartiteDfs(adj,color,it,!col)==false)
                  return false;
            }
            //if the color of current element is same as previous element means it is visited previously so it is not possible
            //to assign differnt color to adjacent element
            else if(color[it]==col)
            {
                return false;
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
               if(isBipartiteDfs(adj,color,i,0)==false)
               {
                  return false;
               }
            }
        }
        return true;
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
