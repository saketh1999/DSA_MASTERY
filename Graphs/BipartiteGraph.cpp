//This code will involve the coding of Bipatite graph

//We are doing this using two methods, BFS and DFS
//First BFS:
class Solution {
    private :
    bool bipartite_checker(int c, vector<int> adj[],vector<int> &color)
    {
        //BFS do BFS
        
        queue<int> q;
        q.push(c);
        color[c]=0;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto x:adj[front] )
            
            if(color[x]==-1)
            {
                color[x]= !color[front];
                q.push(x);
                
            }
            else if (color[x]==color[front])
            {
                //cout<<"y";
                return false;
            }
        }
        return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //our colors-> [0,-1]
	    vector<int> color;
	    for(int i=0;i<V;i++)
	    {
	        color.push_back(-1);
	        
	    }
	    //next step
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            bool ans = bipartite_checker(i,adj,color);
	            if(ans==false) return false;
	        }
	    }
	    return true;
	}

};

//Second DFS:
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int bipartite_checker(int i,vector<int>adj[],vector<int> &color,int clr)
    {
        color[i]=clr;
        
        for(auto x:adj[i])
        {
            if(color[x]==-1)
            {
                 if(bipartite_checker(x,adj,color,!clr)==false)
                {return false;}
            }
            else if(color[x]==clr)
            {
                
                 return false;
            }
          
        }
        return true; //At some point we need to return true also from DFS -> else it wont work
        
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> color;
	    for(int i=0;i<V;i++)
	    color.push_back(-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(bipartite_checker(i,adj,color,0)==false)
                {return false;}
	        }
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