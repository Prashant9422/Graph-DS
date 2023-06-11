#include<bits/stdc++.h>
using namespace std;

class Province
{  
    private:
    void dfsProvince(int start,vector<int> adj[],int vis[])
    {
        vis[start]=1;
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfsProvince(it,adj,vis);
            }
        }
    }
    public:
    int noOfProvince(vector<vector<int>> v,int V)
    {
        //the way to convert the adjcancey matrix to adjcaency list
        vector<int> adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                // i!=j is for removing the self loop 
                if(v[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int vis[V]={0};
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                dfsProvince(i,adj,vis);
            }
        }
        return count;
    }
     
};
int main()
{
    vector<vector<int>> arr
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    Province obj;
    cout<<obj.noOfProvince(arr,3);
    return 0;
}