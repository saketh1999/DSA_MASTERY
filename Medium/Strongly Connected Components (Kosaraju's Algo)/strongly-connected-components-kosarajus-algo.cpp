//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
      void dfs2(vector<vector<int>> & adj,int i, vector<bool> & visited )
    {
        visited[i]=true;
        for(auto x: adj[i])
        {
            if(visited[x]==false)
            {
                dfs2(adj,x,visited);
            }
        }
     
        
    }
    void dfs(vector<vector<int>> & adj,int i, vector<bool> & visited, stack<int> & s )
    {
        visited[i]=true;
        for(auto x: adj[i])
        {
            if(visited[x]==false)
            {
                dfs(adj,x,visited,s);
            }
        }
        s.push(i);
        
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> visited(V,false);
        stack<int> s;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            dfs(adj,i,visited,s);
        }
        
        
        //Reverse the graph
        vector<vector<int>> rAdj(V);
        
        for(int i=0;i<adj.size();i++)
        {
            for(auto x : adj[i])
            {
                rAdj[x].push_back(i);
            }
        }
        
        //Now DFS
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        int ans=0;
        while(!s.empty())
        {
            int front = s.top();
            s.pop();
            
            if(!visited[front])
            {
                ans++;
                dfs2(rAdj,front,visited);
            }
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends