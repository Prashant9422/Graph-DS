//Find the number of province using dfs algorithm.In this you are allowed to visit the horizontal,vertical,diagonaly.
#include <bits/stdc++.h>
using namespace std;

class solution
{
    private:
    void findnumIsland_dfs(vector<vector<char>>& grid,vector<vector<char>>& vis,int row,int col)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=1;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int drow=row+i;
                int dcol=col+j;
                if(drow>=0 && drow<m && dcol>=0 && dcol<n && grid[drow][dcol]=='1' && !vis[drow][dcol])
                {
                    
                    findnumIsland_dfs(grid,vis,drow,dcol);
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
                    findnumIsland_dfs(grid,vis,i,j);
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
