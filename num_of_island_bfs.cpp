//Find the number of province using bfs algorithm.In this you are allowed to visit the horizontal,vertical,diagonaly.
#include <bits/stdc++.h>
using namespace std;

class solution
{
    private:
    void findnumIsland(vector<vector<char>>& grid,vector<vector<char>>& vis,int row,int col)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int drow=q.front().first;
            int dcol=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow=drow+i;
                    int ncol=dcol+j;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1'&& !vis[nrow][ncol])
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<char>> vis(m,vector<char> (n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    findnumIsland(grid,vis,i,j);
                }
            }
        }
        return count;
    }
    
};



int main()
{
    vector<vector<char>> grid
    {
        {'0','1'},{'1','0'},{'1','1'},{'1','0'}
    };
    solution obj;
    cout<<obj.numIslands(grid)<<" ";
    return 0;
}
