//This code we will look at find the topological sort for a DAG (Directed Acyclic Graph) = >only possible
//TC -> O(V+E), SC O(V+E)(linear)
//We use a stack to store the resultant sort

#include <iostream>

#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void create_adjlist(unordered_map<int,list<int> > &adjlist, vector<vector<int> > & edges)
{
    //now we have to create and DAG

    for(int i=0;i<edges.size();i++)
    {
        for(int j=0;j<edges[i].size();i++)
            {
             int u = edges[i][0];
             int v = edges[i][1];

             adjlist[u].push_back(v);//only once since the graph is a directed one.
            }
    }
}
void topological_sort( unordered_map<int,bool> & visited, unordered_map <int, list<int> > & adjlist, stack<int> & t_sort, int src)
{
    visited[src]=true;
    
    for(int x : adjlist[src])
    {
        
        if(!visited[x])
        {
            topological_sort(visited,adjlist,t_sort,x);
        }

    }
    t_sort.push(src);
    return;

}
vector<int> toplogical_sort(vector<vector<int> > & edges, int v, int e)
{
    unordered_map <int, list<int> > adjlist; //this could also be TLE , we could use vector<vector<int>> to get better time

    //creating an directed graph
    create_adjlist(adjlist,edges);

    //now looking into all the tool required
    //1. stack
    //2. visited map

    //vector<int> t_sort; // if you use a vector you will have to reverse the vector after the sort
    stack <int> t_sort;

    unordered_map<int,bool> visited; // using this could cause a bit of TLE so we could use
    // vector<bool> visited 

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            topological_sort(visited,adjlist,t_sort,i);
    }
    
//for stack we can do this to get the solution

while(!t_sort.empty())
{
    cout<<t_sort.top()<<" "; //printing the sort
    t_sort.pop();
}
}
