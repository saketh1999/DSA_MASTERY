//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfs(vector<int> adj[],int v, vector<int> &visited, vector<int> &pathVis)
  {
      
      visited[v]=1;
      pathVis[v]=1;
      for(auto x : adj[v])
      {
          if(visited[x]==0)
          {
                
              bool ans = dfs(adj,x,visited,pathVis);
              if(ans)return true;
          }
          else if(visited[x]==1 && pathVis[x]==1 )
          return true;
      }
      pathVis[v]=0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        
        vector<int> pathVis(V,0);
        bool ans;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
             ans=dfs(adj,i,visited,pathVis);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends