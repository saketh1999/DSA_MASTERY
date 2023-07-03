//In this code we will learn to get a topological sort using BFS, known as Kahn's algorithm
//TC -> O(V+E), SC O(V+E)(linear)
//It has 3 steps
//1. Create an Indegree vector for all the nodes/vertices
//2. push all the nodes with indegree 0 into the queue.
//3. Do normal BFS with decrementing indegree value for each node when you visit it and push into the queue
// if the indegree =0.


#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> KahnAlgo(vector<vector<int>> edges, int n, int e)
{
    unordered_map<int , list<int>> adjlist;
    //creating the adjlist
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<edges[i].size();i++ )
        {   
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
        }
    }

    //finding the indegree for all the vertices
    vector<int> indegree(n,0); // this could potentially be a map also depending on the data
    for(auto x : adjlist)
    {
        for(auto y : x.second)
        {
            indegree[y]++;
        }
    }

    //For all elements with indegree 0 , push into queue
    queue <int> bfs_q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
            bfs_q.push(i);
        }

    }

    //Now do bfs
    vector<int> ans;
    while(!bfs_q.empty())
    {
        int front_node=bfs_q.front();
        bfs_q.pop(); //now are poping the element from the q
        
        //Store the ans
        ans.push_back(front_node);

        for(auto x : adjlist[front_node])
        {
            indegree[x]--;//important to reduce the count to 0, so that element will eventually be added to the queue.
            if(indegree[x]==0)
                bfs_q.push(x);
        }

    }

    return ans;
}
