//In this code lets try to detect a cycle in an undirected graphs DFS and BFS respectively
//we are following Luv Babar course : https://www.youtube.com/watch?v=1cSzxlhxOw8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=96
//This code will work for disconnected graph also

 #include <iostream>
 #include <list>
 #include <queue>
 #include <unordered_map>
 using namespace std;

void prepare_adjlist(unordered_map<int , list<int>> &adjlist,vector< vector<int>> &edges)
{
    for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjlist[u].push_back(v);
        }
}

bool cycle_detect_bfs(unordered_map<int , list<int>> &adjlist, unordered_map<int,bool> visited, int src)
{
    queue<int> bfs_q;
    unordered_map<int,int> parent;

    bfs_q.push(src);
    visited[src]=true;

    while(!bfs_q.empty())
    {
        int front_node= bfs_q.front();
        bfs_q.pop();
        for(auto x : adjlist[front_node])
        {
            if(!visited[x])
            {
                bfs_q.push(x);
                visited[x];
                parent[x]=front_node;//very important , storing the parent
            }
            else if(visited[x]==true && parent[front_node]!=x) // Cycle condition
            {
                return true;
            }
        }
    }
}

bool cycle_detect_dfs(unordered_map<int , list<int>> &adjlist, unordered_map<int,bool> visited, int src,int parent)
{
    visited[src]=true;
    

    for(auto x : adjlist[src]) // x-> neighbour
    {
        if(!visited[x])
        {
            
            bool cycle_detected = cycle_detect_dfs(adjlist,visited,x,src);//parent is updated in this line by "src"
            if(cycle_detected) return true;
            
        }
        else if(visited[x]==true && parent!=x)
        {
            return true;
        }
    }
    return false;
}

//Start from here
bool Cycle_detection( vector< vector<int>>edges, int n /*vertices*/, int m /*edges*/)
{

    //create an adj list 

    unordered_map<int , list<int>> adjlist;//this could also be TLE , we could use vector<vector<int>> to get better time
    unordered_map<int,bool> visited;// using this could cause a bit of TLE so we could use vector<bool>

    prepare_adjlist(adjlist,edges);

    //Travese all vertices(even disconnected) BFS
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            bool is_cycle = cycle_detect_bfs(adjlist,visited,i);
        }
    }

    //Travese all vertices(even disconnected) DFS
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            bool is_cycle = cycle_detect_dfs(adjlist,visited,i,-1);
        }
    }

}