//THis code is written to support BFS for dicontinued graphs
//YT:https://www.youtube.com/watch?v=b5kij1Akf9I&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=94
//No Main Function here

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;



void prepareAdjlist (unordered_map<int,list<int> > &adjlist,vector<pair<int,int>> &edges)
{
    //traverse all the edges provided
    for(auto x : edges)
    {
        adjlist[x.first].push_back(x.second);
        adjlist[x.second].push_back(x.first);

    }
}
void print_bfs( unordered_map<int,list<int> > &adjlist,vector<int> &bfs_ans, unordered_map<int,bool> &visited,int src)

{
    queue<int> q;
    //only done one time
    q.push(src);
    visited[src]=true;

    while(!q.empty()){//traverse the queue till we get bfs

    int front_node=q.front();
    q.pop();
    bfs_ans.push_back(front_node);
    
        for(auto x : adjlist[front_node])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
            }
        }
    
    }

}
void BFS(int vertices, vector<pair<int,int>>edges)
{
    unordered_map<int,list<int> > adjlist; //if list is changed to set we will get the BFS in increasing order for each vertice
    vector<int> bfs_ans;
    unordered_map<int,bool> visited;

    //Lets create the adjlist
    prepareAdjlist(adjlist,edges); //Now the list is ready

    
    //for a connected graph, we can call the below command once and the whole BFS will be printed
    //print_bfs(adjlist,bfs_ans,visited,i);

    //Traverse all components of the graph (including disconnected)
    //In case we want to traverse BFS from a particular start vertice, we must pass a src vertice in place of 
    // i in line 58, along with the following code, this will print for disconnected graph starting from a src
    //vertice
    for(int i=0;i<vertices;i++)
    {
        if(visited[i]==false)//this will traverse even the diconnected vertices in the graph
        print_bfs(adjlist,bfs_ans,visited,i);
    }
}
//Didnt write main function 
//This code was to cover the corner case of diconnected graphs.