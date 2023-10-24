//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private: 

void dfs(map<int,list<int>>&adj,vector<int> &visited,vector<int> &path,int s, int &d)
{
    path.push_back(s);
    //cout<<s<<endl;
    if(s==d)
    {
        
        res.push_back(path);
    
        return;
    }
      visited[s]=1;
    
    for(auto x: adj[s])
    {
        if(visited[x]==0)
        {
          
            dfs(adj,visited,path,x,d);
            visited[x]=0;
            path.pop_back();
        }
    }
}
public:

vector<vector<int>> res;
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int> path;
	    int count=0;
	    vector<int> visited(n,0);
	    
	    map<int,list<int>> adj;
	    
	    for(auto it : edges)
	    {
	        int u =it[0], v = it[1];
	        {
	            adj[u].push_back(v);
	         
	        }
	    }
	    
	    dfs(adj,visited,path,s,d);
	    
	    return res.size();
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends