//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
bool bfs(vector<int>adj[],int i, vector<int> &color)
{
    color[i]=0;
    queue<int> q;
    
    q.push(i);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        
        for(auto x: adj[front])
        {
            if(color[x]==-1)
            {
                color[x] = !color[front];
                q.push(x);
            }
            
            else if(color[x]==color[front])
            {
                return false;
            }
        }
    }
return true;
    
}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    queue<int> q;
	    
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1){
	        bool ans =bfs(adj,i,color);
	        if(ans==false)return false;}
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends