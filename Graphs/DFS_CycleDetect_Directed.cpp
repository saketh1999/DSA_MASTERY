//This code will focus on checking if there is a cycle in a directed graph using DFS
//YT:https://youtu.be/Tl5qbEmEQyY
//We use a DFS visited array

#include<iostream>
#include <list>

using namespace std;

void create_adjlist(unordered_map<int , list<int>> adjlist,vector<pair <int, int >> edges)
{
    for(auto x : edges)
    {
        adjlist[x.first].push_back(x.second); //since directed graph we only do this.
    }
}

bool dfs_cycle_detection(unordered_map<int , list<int>> &adjlist,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfs_visited,int src)
{
    visited[src]=true;

    dfs_visited[src]=true;

    for(auto x : adjlist[src])
    {
        if(!visited[x])
        {
            bool is_cycle = dfs_cycle_detection(adjlist,visited,dfs_visited,x);

            if(is_cycle)
                return true;
        }
        else if(visited[x]==true && dfs_visited[x]==true)
        {
            return true;
        }
    }
    dfs_visited[src]=false; //important to mark it false after you dont find any cycle in it
    return false;
}
//Starts here
bool detectCycleInDirectedGraph( int n, vector<pair <int, int >> edges)
{
    bool is_cycle;
    unordered_map<int , list<int>> adjlist;//this could also be TLE , we could use vector<vector<int>> to get better time

    //creating the adjlist
    create_adjlist(adjlist,edges);

    unordered_map<int,bool> visited,dfs_visisted;// using this could cause a bit of TLE so we could use vector<bool>
    //Travese all the vertices using DFS
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            is_cycle=dfs_cycle_detection(adjlist,visited,dfs_visisted,i);
        
    }
    return is_cycle;
    
}