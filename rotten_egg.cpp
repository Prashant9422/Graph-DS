//In this code bfs algorithm is used
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int vis[n][m];
        int count_one=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //It keeps the record of how many cell have the values rotten egg whose value is 2
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
                //It keeps the record of how many numbers are present in the grid initially
                if(grid[i][j]==1)
                {
                    count_one++;
                }
            }
        }
        int cnt=0;
        int tm=0;
        //allowed only horizontal and vertical movement
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                    vis[nrow][ncol]=2;
                }
            }
        }
        if(count_one!=cnt)
        {
            return -1;
        }
        else
            return tm;
    }

};

int main()
{
  vector<vector<int>>grid{{0,1,2},{0,1,2},{2,1,1}};
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";
    return 0;
}
