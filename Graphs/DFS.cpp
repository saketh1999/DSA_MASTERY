/*DFS is recursive traversal for graphs, YT: https://www.youtube.com/watch?v=lo1P6bhsoG4 */

#include <iostream>
#include <map>
#include<list>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T> > adjlist;
    public:
    void add_edge(T v1, T v2)
    {
        //creating an undirected graph
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }
    void dfs_helper(T src, map<T,bool> & mp) //& is important since, the map is update in each recursion
    {   int debug=0;// this debug will help to print each vertix with visited value in the map
        
        cout<<src<<" "; //Printing the dfs traversal 
        
        if(debug)
        {cout<<" Visited = "<<mp[src]<<endl;}


         mp[src]=true;//adding the key(source vertix) and setting the visited as true
        for(auto i : adjlist[src])
        {
            if(!mp[i])
            {
                dfs_helper(i,mp);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> v_mp;//visited map
       
        for(auto p : adjlist)
        {
            T vertix = p.first;
            v_mp[vertix]= false;
        }
        dfs_helper(src,v_mp);
    }
};

int main(){
  Graph <int> g;
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,3);
    g.add_edge(1,2);
    g.dfs(0);
}