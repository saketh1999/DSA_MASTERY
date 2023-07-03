//In This code we will learn to code the MST using Prims Algo
//This Algo will be using 3 vectors data structure to generate the
//MST.

//1. Key Vector is used to find the min distances during the MST
//generation. (It will store the weights of the MST)
//2. MST(bool vector) vector to store if the node is part of the MST
//3. Parent vector to store the parents of each node of MST

//Dry Run in Notes

#include<iostream>
#include<unordered_map>
#include<list>
#include <limits>

#include<queue>
using namespace std;
class Graph{
    unordered_map<int ,list<pair<int,int> > > adjlist;

    public:
    void addEdge(int u,int v,int w)
    {
        adjlist[u].push_back(make_pair(v,w));
    }

    void Prims(int src,int n)
    {
        //Key Vector
          //Also setting all the key values of the node to INT_MAX
        vector<int> key(n,INT_MAX);
      

        //MST Tracker 
        //Also setting all the values to false
        vector<bool> mst(n,false);

        //Parent vector
        //setting all parent node values to -1
        vector<int> parent(n,-1);

        //Priority Queue to speed up the Algo
         //priority_queue<pair<int,int>,greater<int> > pq;


        //marking the src node
        key[src]=0;
        parent[src]=-1;
        //pq.push(make_pair(0,src)); //PQ
        
        //Algo Start for all nodes
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            int u;
            //1. Find the min node
            //If we do it this was the TC is O(N^2)
             
            for(int v=0;v<n;v++)
            {
                if(mst[v]==false && key[v]<mini)
                {
                    u=v;
                    mini=key[v];
                }
            }
            //But if we use Priority Queue we will get O(NlogN)
                // u=pq.top().second;
                // pq.pop();

            //2. mark min node as true;
            mst[u]=true;

            //3. check its adjacent node
            for(auto it: adjlist[u])
            {
                int v=it.first;
                int w=it.second;
                if(mst[v]==false && w<key[v])
                {
                    parent[v]=u;
                    key[v]=w;
                    //pq.push(make_pair(key[v],v)); //Priority Queues
                }
            }
        }

    //Storing the resulting MST as follows
    vector<pair<pair<int,int>,int> >result;

    for(int i=1;i<n;i++)//start from the second index
    {
        result.push_back({{parent[i],i},key[i]});
    }

    //Printing the sol
    for(auto p: result)
    {
        cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
    }

    }


};

int main()
{
    Graph g;
    g.addEdge(0,1,5); g.addEdge(0,2,3); g.addEdge(1,2,2); g.addEdge(1,3,6); g.addEdge(2,3,7);
    g. addEdge(2,4,4); g.addEdge(2,5,2); g.addEdge(3,4,-1); g.addEdge(4,5,-2);
    g.Prims(0,5);
}