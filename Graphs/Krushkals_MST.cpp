//We will do Krushkal Algo using Union sets Data structure
//(Notes are written and YT:https://www.youtube.com/watch?v=KxLtIrCyXwE)
//We have 2 main Algo to understand 
//1.Find and 2.Union

//We will implement the optimized version called Union by Rank and Path Compression

//We need two data stuctures
//Parent[i]-> represents the parent of the i'th element
//rank[i] -> represents the height of the element in the Union tree

//Now using the above we will right the find and Union Algo

//Krushkal Algo
//1.We dont need Adjacency list
//2.We need a linear DS
//3.We need to store the wt, u and v and sort the list based on the weight.
/*
4.After sorting we will traverse one element at a time and check if
the u and v belong to the same set (if the do we ignore), if they do not
belong the same set then we make them union set and while doing this we
add the weight of the MST in a integer wt_mst
*/

//5. Return wt_mst

//Dry Run in Notes
#include <iostream>

using namespace std;
bool cmp(vector<int> & a, vector<int> &b)
{
    return a[2]<b[2]; //comparing the weights and sorting using own algo
}
void makeSet(vector<int> &parent , vector<int> &rank, int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(vector<int> & parent,int node)
{//We recursively find the parent of the current node
    if(parent[node]==node)//reached the root of the tree, topmost parent
    {
        return node;
    }
    return parent[node]=findParent(parent,parent[node]);//This is the Path compression
    //we will store the topmost parent of a node in the parent array (this is called caching)
}
int unionSet(int u,int v, vector<int> & parent, vector<int> &rank)
{
    //Union has 3 function
    //1. find the parent of the elements of the two sets
    //2.Compare the ranks
    //3.Update the Parents based on the ranks (As coded below)
    u = findParent(parent,u);
    v = findParent(parent,v);

    //Now we are doing the Union by Rank
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else{//if ranks are equal then we can make anyone the parent and update 
    //the rank of the parent.
        parent[v]=u;
        rank[u]++;
    }
}
int miniSpanningTree(vector<vector<int> > & edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent,rank,n);

    sort(edges.begin(),edges.end(),cmp);//Sorting the edges based on weights
    int wt_mst=0;
    for(int i=0;i<edges.size();i++)
    {

        int u=findParent(parent,edges[i][0]);//Finding the parent of u
        int v=findParent(parent,edges[i][1]);//Finding the parent of v
        int wt=edges[i][2];
        if(u!=v)//Indicates u and v have different parent so we find the union.
        {
            wt_mst+=wt;
            unionSet(u,v,parent,rank);//Making Union of u and v
        }

    }
    return wt_mst;
}

