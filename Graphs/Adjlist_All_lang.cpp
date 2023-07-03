/*This code will help to understand the coding of a graph (in this case undirected/directed weighted graph) using adjacency list for all cases*/
/* The code in in reference to the following YT video: https://www.youtube.com/watch?v=drpdVQq5-mk */
/*list or vector can be used for this*/
#include <iostream>
#include <map>
#include<unordered_map>
#include <cstring>
#include <list>
using namespace std;

class Graph
{
    unordered_map<string,list<pair<string,int> > > adjlist;
    public:
    void add_edge(string v1,string v2, bool isbidir, int weight)//adding edge function
    {
        adjlist[v1].push_back(make_pair(v2,weight));
        if(isbidir)
        {
         adjlist[v2].push_back(make_pair(v1,weight));   
        }
    }
    void print_graph()
    {
        unordered_map<string,list<pair<string,int> > >::iterator it;
        for(it = adjlist.begin();it!=adjlist.end();it++)
        {
            cout<<"Vertix "<< it->first<<" -> ";
            list<pair<string,int> > l = it->second;
            list<pair<string,int> >::iterator it2;
            for(it2=l.begin();it2!=l.end();it2++)
            {
                cout<< it2->first <<"("<<it2->second<<"), ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g;
    g.add_edge("A","B",true,20);
    g.add_edge("B","D",true,40);
    g.add_edge("A","C",true,10);
    g.add_edge("C","D",true,40);
    g.add_edge("A","D",false,50);
    g.print_graph();
    return 1;
}