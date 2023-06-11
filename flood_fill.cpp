
#include <bits/stdc++.h>
using namespace std;

class solution
{
    private:
    void dfsfloodfill(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int Color, int newColor)
    {
        ans[sr][sc]=newColor;
        int m=image.size();
        int n=image[0].size();
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==Color && ans[nrow][ncol]!=newColor)
            {
                dfsfloodfill(nrow,ncol,image,ans,Color,newColor);
            }
        }
        
    }
    public:
    vector<vector<int>> findfill(int sr,int sc,vector<vector<int>>& image,int newColor)
    {
        int Color=image[sr][sc];
        vector<vector<int>> ans=image;
        dfsfloodfill(sr,sc,image,ans,Color,newColor);
        return ans;
    }

};

int main()
{
    vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	int sr=1;
	int sc=1;
	int newColor=2;
    solution obj;
    vector<vector<int>> v=obj.findfill(sr,sc,image,newColor);
    for(auto i:v)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
