//Find the number of enclave in which we first check the first row, column and last row and last column.If we encounter any element
//push into the queue. Through queue element, adjacent cell can be traversed.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //Traverse first row, last row, first column and last column
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};

int main()
{
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;
	return 0;
}
