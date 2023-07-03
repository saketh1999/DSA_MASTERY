//This code we will learn to find the shortest path in a graph for an undirected graph using BFS
//YT:https://youtu.be/abIEXKFpLNE

//We create the parent array/map to store the key and the correponding parent for the node.
//Now we can find the shortest path by picking the destination and backtacking the parent values till we reach 
//-1 as a parent value (which indicates the source node)

//TC and SC = O(V+E)

//GFG Question: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1


#include<iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

void createAdjlist(unordered_map<int, list<int> > &adjlist,vector<vector<int>> edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u= edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

}
vector<int>shortest_path_helper(unordered_map<int, list<int> > &adjlist, unordered_map<int,bool> &visited, unordered_map<int, int> &parent_map,int src)
{
    //queue for BFS
    queue<int> bfs_q;
    //pusing the src node into q
    bfs_q.push(src);
    visited[src]=true;
    parent_map[src]=-1;

    while(!bfs_q.empty())
    {
        int front_node=bfs_q.front();
        bfs_q.pop();
        for(int nbr: adjlist[front_node])
        {
            if(!visited[nbr])
            {
                visited[nbr]=true;
                parent_map[nbr]=front_node;
                bfs_q.push(nbr);

            }

        }
    }

}
vector<int>shortestPath(int v, int e, vector<vector<int>> edges,int src,int des)
{
        //adjlist
    unordered_map<int, list<int> > adjlist;

    //create the adj list
    createAdjlist(adjlist,edges);

    unordered_map<int,bool> visited;
    unordered_map<int, int> parent_map;

    int src=1;
    //Now we have to do bfs
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            shortest_path_helper(adjlist,visited,parent_map,src);
        }
    }

    //prepare answer path
    vector<int>ans;
    int current_node=des;
    ans.push_back(des);
    while(current_node!=src)
    {
        current_node=parent_map[current_node];
        ans.push_back(current_node);
    }
    //Reason why this will give us the shortest path is because BFS does Shortest path by default
    //Finally the answer is the reverse of the above ans vector
    reverse(ans.begin(),ans.end());
    return ans;

}
int main()
{





}
