//Calulate the distance between nearest 1.In this it take two matrix visited and distance matrix. Visited matrix contain visited 
//cell and distance matrix contain the distance between nearest 0 and 1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>>nearest(vector<vector<int>>grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            dist[row][col]=steps;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        
        return dist;
    }
    
};

int main()
{
   vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}
