//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 private:
    void dfs(map<int,list<pair<int,int> >> &adjlist, stack<int>&topo,vector<bool> &visited,int v)
    {
        visited[v]=true;
        
        for(auto x : adjlist[v])
        {
            int vt = x.first;
            int wt = x.second;
            
            if(visited[vt]!=true)
            {
                dfs(adjlist,topo,visited,vt);
            }
        }
        topo.push(v);
        return;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        // vector<int> dis(N,-1);
        
        //create adjlist
        map<int,list<pair<int,int> >> adjlist;
        for(auto x: edges)
        {
            int i = x[0];
            int j = x[1];
            int w = x[2];
            
            adjlist[i].push_back({j,w});
        }
        stack<int> topo;
        vector<bool> visited(N,false);
        dfs(adjlist,topo,visited,0);
        vector<int> dis(N,-1);
        dis[0]=0;
       while(!topo.empty())
       {
           int front = topo.top();
           topo.pop();
           for(auto x : adjlist[front])
           {
               int v = x.first;
               int w = x.second;
               if(dis[v]==-1)
               {
                   dis[v]=dis[front]+w;
               }
               if(dis[v]> dis[front]+w)
               {
                   dis[v]=dis[front]+w;
               }
           }
           
       }
       return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends