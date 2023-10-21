//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  void createList(map<int,list<int>>& adjlist, vector<vector<int>> adj, int V)
  {
      for(int i=0;i<adj.size();i++)
      {
          for(int j=0;j<adj[0].size();j++)
          {
              if(i!=j && adj[i][j])
              {
                  adjlist[i].push_back(j);
                  adjlist[j].push_back(i);
              }
          }
      }
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        map<int,list<int> > adjlist;
        createList ( adjlist,adj,V);
        
        vector<bool> visited (adj.size(),false);
        
        queue<int> q;
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                 q.push(i);
                 visited[i]=true;
                 ans++;
                       while(!q.empty())
        {
            int front =q.front();
            q.pop();
           
            for(auto nbr : adjlist[front])
            {
               if(!visited[nbr])
               {
                   visited[nbr]=true;
                   q.push(nbr);
                   
               }
            }
        }
            }
       
        
        }
        return ans;
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends