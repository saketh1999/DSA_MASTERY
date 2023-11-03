//This Code will cover Kosaraju Algo to find the SCCs in a given graph

//1. DFS of the current graph - > store the traversal in a stack
//2. Reverse the graph 
//3. DFS on the Reversed graph , taking the stack elements 

//GFG: https://shorturl.at/bAEHZ

//Code:

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int v,vector<vector<int>>& adj, stack<int>&st,map<int,bool> &visited)
    {
        visited[v]=true;
        
        for(auto i : adj[v])
        {
            if(!visited[i])
            {
                dfs(i,adj,st,visited);
            }
        }
        st.push(v);
        return;
        
    }
    void dfs2(int v,vector<vector<int>>& adjT,map<int,bool> &visited)
    {
        visited[v]=true;
        
        for(auto i : adjT[v])
        {
            if(!visited[i])
            {
                dfs2(i,adjT,visited);
            }
        }
      
        
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //given the adj list
        
        //lets first do a DFS 
        map<int,bool> visited;
        
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,st,visited);
            }
        }
        
        //Now reverse the Graph
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++)
        {
            for(int k: adj[i])
            {
                adjT[k].push_back(i);
            }
        }
        int scc=0;
        //Perform the DFS on the order of Finishing time
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        //int scc=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!visited[node])
            {
                scc++;
                dfs2(node,adjT,visited);
            }
        }
        return scc;
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