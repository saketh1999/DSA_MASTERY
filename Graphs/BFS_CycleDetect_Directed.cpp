//This code we will code up how to tell if the graph consists of a cycle or not using BFS 
//in an directed Graph
//This algo is same as Kahn with only difference being that count is calculated.

#include <iostream>
#include <list>
#include <queue>

using namespace std;

bool bfs_cycle_detection(int v, int e, vector<vector<int>> edges)
{
    unordered_map<int, list<int> > adjlist;

    //creating the map
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
    }

    //now find the indegree for all vertices
    vector<int> indegree(v,0);
    for(auto x : adjlist)
    {
        for(auto y : x.second)
        {
            indegree[y]++; //incrementing the value of y in the vector
        }
    }

    //add all vertices with indegree 0 to the queue
    queue<int> bfs_q;
    int count=0;

    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        bfs_q.push(i);
    }

    //Now start BFS

    while(!bfs_q.empty())
    {
        int front_node=bfs_q.front();
        bfs_q.pop();
        count++;

        for(auto nbr: adjlist[front_node])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            bfs_q.push(nbr);
        }

    }

    if(count == v)//count matches the number of vertices in the graph mean , we dont have a cycle
    return false;
    else return true;

}
