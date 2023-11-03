#include <iostream>
#include <vector>

using namespace std;

class UnionRank
{
    vector<int>rank,parent,size; // we are declaring the parent and rank vectors
    //lets start the coding for this
    public:

    //Create the Disjoint set.

    UnionRank(int n)
    {
        rank.resize(n+1,0); //n+1 -> since we are also doing 1 based indexing
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1; //Union by size -> initial setup
        }
    }

    int findParent(int node)
    {
        if(node==parent[node])
        return node;
        else{
            parent[node] = findParent(parent[node]);
            return parent[node];
        }
    }

    void unionByRank(int u, int v) //This function tells us if the two vertices belong 
    //to the same graph.
    {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if(v_par == u_par) // they have the same parent
        return;

        if(rank[u_par] > rank[v_par])
        {
            parent[v_par] = u_par;
        }
        else if(rank[u_par] < rank[v_par])
        {
            parent[u_par] = v_par;
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }



    void unionBySize(int u, int v) //This function tells us if the two vertices belong 
    //to the same graph.
    {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if(v_par == u_par) // they have the same parent
        return;

        if(size[u_par] > size[v_par])
        {
            parent[v_par] = u_par;
            size[u_par]+= size[v_par];
        }
        else 
        {
            size[u_par] = v_par;
            size[v_par]+= size[u_par];
        }
    }
};
int main()
{
    
    // UnionRank ds(7);
    // ds.unionByRank(1, 2); 
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6); 

    //This is union by size -> gives the same time complexity of 4alpha
     UnionRank ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6); 

    //If 3 and 7 belong to same component
    if(ds.findParent(3) == ds.findParent(7))
        cout<< "same";
    else 
        cout<<"not same";

    ds.unionByRank(3, 7);
cout<<endl;
        if(ds.findParent(3) == ds.findParent(7))
        cout<< "same";
    else 
        cout<<"not same";
    return 0;
}