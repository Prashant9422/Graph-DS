
#include <bits/stdc++.h>
using namespace std;
class solutions
{
  private:
  void dfstraversal(int vis[],vector<int> adj[],int start,vector<int> &dfs)
  {
      vis[start]=1;
      dfs.push_back(start);
      for(auto it:adj[start])
      {
          if(!vis[it])
          {
              dfstraversal(vis,adj,it,dfs);
          }
      }
  }
  public:
  vector<int> finddfs(int V,vector<int> adj[])
  {
      int vis[V]={0};
      int start=0;
    //   vis[start]=1;
      vector<int> dfs;
    //   dfs.push_back(start);

      dfstraversal(vis,adj,start,dfs);
      return dfs;
  }
};
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> &ans)
{
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    solutions s;
    vector<int> ans=s.finddfs(5,adj);
    print(ans);

    return 0;
}
