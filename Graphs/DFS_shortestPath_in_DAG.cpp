//This Code we will see how to find the shortest path for a weighted DAG
//We will use DFS to perform this
//TC and SC -> O(N+E)

//Steps involved
//1.Find the topological sort of the graph
//2. Find the distance Array for the source node.
//Refer the IF condition to generate the distance array -> only thing to remeber

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<limits.h>
using namespace std;

class Graph{
    public: 
    unordered_map<int,list<pair<int,int>> > adjlist;//this adjlist is with the weights of the edges also


    void addEdge(int u,int v,int weight)
    {
        pair<int,int> p =make_pair(v,weight);
        adjlist[u].push_back(p);

    }
    void printAdjlist()
    {
        for(auto x: adjlist)
        {
            cout<<x.first<<" -> ";
            for(auto y: x.second)
            {
                cout << y.first<<"("<<y.second<<") ";//Printing the node along with the weight
            }
        cout<<endl;

        }
        
    }

    void DFS_topologicalSort(int src,unordered_map<int, bool> &visited,stack<int> &top_sort)
    {
        visited[src]=true;

        for(auto nbr: adjlist[src])
        {
            if(!visited[nbr.first])
            {
                DFS_topologicalSort(nbr.first,visited,top_sort);
            }
        }
        top_sort.push(src);//It will only store nodes not weights
        return;

    }

    void ShortestPath(int n,int src,stack<int> &top_sort)
    {
        //Now Distance Array
        vector<int> dis(n,INT_MAX);
        
        dis[src]=0;//marking the source distance as 0

        while(!top_sort.empty())
        {
            int top=top_sort.top();
            top_sort.pop();

            if(dis[top]<INT_MAX)//This is the main condition to get the solution ( we can have < or != INT_MAX)
            {
                for(auto i: adjlist[top])
                {
                    if(dis[top]+i.second<dis[i.first])//Conditon that will give u shortest path.
                    dis[i.first]=dis[top]+i.second;
                }
            }
        }

    cout<<"answer is: "<<endl;
    for(int i: dis)
    {
        cout<<i<<" "; 
    }


    }
};

int main()
{
    Graph g;
// g.addEdge(0,1,5); g.addEdge(0,2,3); g.addEdge(1,2,2); g.addEdge(1,3,6); g.addEdge(2,3,7);
// g. addEdge(2,4,4); g.addEdge(2,5,2); g.addEdge(3,4,-1); g.addEdge(4,5,-2);
g.addEdge(0,1,2); g.addEdge(1,2,3); g.addEdge(2,3,5);g.addEdge(2,4,4);

g.printAdjlist();

    unordered_map<int, bool> visited;
    stack<int> top_sort;
    int n=5; // nodes


    //Topological sort
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.DFS_topologicalSort(i,visited,top_sort);

        }
    }


int src=1; //stating node
g.ShortestPath(n,src,top_sort);

//sol: 2147483647(INT_MAX) 0 2 6 5 3 we are getting the correct

}