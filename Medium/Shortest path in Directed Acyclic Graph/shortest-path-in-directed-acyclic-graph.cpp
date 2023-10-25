//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> dis(N,-1);
        
        //create adjlist
        map<int,list<pair<int,int> >> adjlist;
        for(auto x: edges)
        {
            int i = x[0];
            int j = x[1];
            int w = x[2];
            
            adjlist[i].push_back({j,w});
        }
        
        priority_queue< pair<int,int>  ,vector<pair<int,int>>, greater<pair<int,int >> > pq;
        
        dis[0]=0;
        pq.push({0,0});
        
        
        while(!pq.empty())
        {
            pair<int,int>  front = pq.top();
            pq.pop();
            
            int i = front.second;
          
            int w= front.first;
            
            for(auto x : adjlist[i])
            {
                int e = x.first;
                int wt = x.second;
                
                if(dis[e]==-1)
                {
                    dis[e]=dis[i]+wt;
                    pq.push({dis[e],e});
                }
               else if(dis[e]>dis[i]+wt)
                {
                    dis[e]=dis[i]+wt;
                    pq.push({dis[e],e});
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