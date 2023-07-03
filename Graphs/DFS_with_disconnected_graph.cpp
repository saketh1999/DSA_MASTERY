//This code if for DFS with the support for disconnected graph 
//YT:https://youtu.be/aJa3U-hydXc

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
void prepare_adjlist(unordered_map<int,list<int>> &adjlist,vector<pair<int,int> > edges)
{
    for(auto x : edges)
    {
        adjlist[x.first].push_back(x.second);
        adjlist[x.second].push_back(x.first);
    }
}

void dfs(unordered_map<int,list<int>> &adjlist, unordered_map<int,bool> &visited, int src,vector<int> dfs_ans)
{
    //if(visited[src]==false)
    dfs_ans.push_back(src);
    visited[src]=true;

    for(auto x : adjlist[src])
    {
        if(visited[src]==false)
        {
            dfs(adjlist,visited,x,dfs_ans);
        }
    }
}

void graph(int vertices, vector<pair<int,int> > edges)
{
    unordered_map<int,list<int>> adjlist;//this could also be TLE , we could use vector<vector<int>> to get better time
    unordered_map<int,bool> visited;// using this could cause a bit of TLE so we could use
    vector<int> dfs_ans;
    prepare_adjlist(adjlist,edges);

    //Travesing all the nodes using DFS, even disconnected onces

    for(int i=0;i<vertices;i++)
        if(visited[i]==false)
            dfs(adjlist,visited,i,dfs_ans);

}
