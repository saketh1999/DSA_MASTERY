//In this code we will learn to find the edges that are bridges in the given graph
//if any are present.
//We will use 3 arrays + parent 

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
    unordered_map<int, list<int> > adjlist;
    vector<vector<int>> res;
    public:
    void addEdge(int u,int v)
    {
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

   void BridgeAlgo_helper(int node,vector<int> &discovery,vector<int> &lowest_discovery,int parent, unordered_map<int, bool> &visited,int timer)
    {
        //Inside this function we will implement the main checks
        //we have 5 main checks 

        //first lets do the template of DFS
        visited[node]=true;
        discovery[node]=lowest_discovery[node]=timer;timer++;
        
        for(auto nbr : adjlist[node])
        {
            if(!visited[node])
            {
                //Check 1.
                if (nbr == parent)
                { continue;}

                //Check 2. 
                if(!visited[nbr])
                {
                    BridgeAlgo_helper(nbr,discovery,lowest_discovery,node,visited,timer);
                    
                    //Check 3. Updating lowest_discovery
                    lowest_discovery[nbr]=min(lowest_discovery[nbr],lowest_discovery[node]);

                    //Check 4. Edge is Bridge
                    if(lowest_discovery[nbr]> discovery[node])
                    {
                        vector<int> ans;
                        ans.push_back(node);
                        ans.push_back(nbr);

                        res.push_back(ans);
                    }
                
                }
            }
            else{
                //Check 5. back edge
                lowest_discovery[node]=min(lowest_discovery[node],discovery[nbr]);
            }
        }
  
    }

    void BridgeAlgo(int n)
    {
        int timer=0;//This will keep track of the timer
        vector<int> discovery(n,-1);
        vector<int> lowest_discovery(n,-1);

        int parent;
        unordered_map<int, bool> visited;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                 BridgeAlgo_helper(i,discovery,lowest_discovery,parent,visited,timer);

            }
        }
        cout<<"Edges are"<<endl;
    
        for(int i=0;i<res.size();i++)
        {
            
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }
       

    }

};

int main()
{
    Graph g;
    g.addEdge(0,1);  g.addEdge(1,2); g.addEdge(1,3); g.addEdge(2,3);
    g. addEdge(2,4); g.addEdge(2,5); g.addEdge(3,4); 
    g.BridgeAlgo(6);


}