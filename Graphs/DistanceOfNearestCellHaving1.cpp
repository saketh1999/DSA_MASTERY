//GFG:https://rb.gy/rhk5f
//Stiver Graph Playlist - 13
//Distance of nearest cell having 1
//Keep in mind that only BFS works for this Algo

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    //This question can be solved by BFS only since only it will check all the nodes that are a the same distance
	    // together
	    
	    //Now
	    int r=grid.size();
	    int c=grid[0].size();
	    vector<vector<int> > visited(r,vector<int>(c,0));
	    
	    vector<vector<int> > dis(r,vector<int>(c,0));
	    
	     queue<pair<pair<int,int> ,int>> q;
	     
	     
	     for(int i=0;i<grid.size();i++)
	     {
	         for(int j=0;j<grid[i].size();j++)
	         {
	             if(grid[i][j]==1)
	             {
	                 q.push({{i,j},0});
	                 visited[i][j]=1;
	             }
	             else{
	                 visited[i][j]=0;
	                 
	             }
	         }
	     }
	     int delrow[4]={-1,0,1,0};
	     int delcol[4]={0,1,0,-1};
	     
	     while(!q.empty())
	     {
	         int x = q.front().first.first;
	         int y = q.front().first.second;
	         int d =  q.front().second;
	         
	         q.pop();
	         
	         dis[x][y] = d;//This is key ->. we need to store the distance or the required resultant like this.
	         
	         for(int i=0;i<4;i++)
	         {
	             int nrow=x+delrow[i];
	             int ncol=y+delcol[i];
	             
	             if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && visited[nrow][ncol]==0)
	             {
	                 visited[nrow][ncol]=1;
	                 q.push({{nrow,ncol},d+1});
	                 
	             }
	         }
	         
	         
	         
	         
	     }
	     return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends