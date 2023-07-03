//In This code we will learn to code the Djisktra's Single Source Shortest Path
//Algorithm is for both directed and undirected graphs.

//YT: https://www.youtube.com/watch?v=dVUR3Rm6biE&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=105

#include <iostream>
#include <list>
#include <set>
#include <unordered_map>


using namespace std;
class Graph{

    unordered_map<int, list<pair<int,int> > > adjlist;
    vector<int> distance;//distance vector
    public:
    
    void addEdge(int u,int v, int w)
    {
        adjlist[u].push_back(make_pair(v,w)); //only one direction since its a directed graph
    }

    vector<int> Dijsktra(int src,int n)
    {
        for(int i=0;i<n;i++)
        distance.push_back(INT_MAX);// we initiall assign all the values to infinity

        set<pair<int,int>> s; //set to store the (distance,node)
        
        //now we update the src node distance to 0
        distance[src]=0;

        //pushing the pair into the set

        s.insert(make_pair(distance[src],src));
   
        while(!s.empty())
        {
            auto top=*(s.begin());//saving the first value 

            s.erase(s.begin());//poping the first value in the set

            for(auto nbr : adjlist[top.second])
            {
                if(top.first+nbr.second<distance[nbr.first])
                {
                    auto record = s.find(make_pair(distance[nbr.first],nbr.first));
                    //if record found erase it
                    if(record!=s.end())
                    {
                        s.erase(record);
                    }
                    //updating the distance vector
                    distance[nbr.first]=   top.first+nbr.second;
                    
                    //pusing the record into set
                    s.insert(pair(distance[nbr.first],nbr.first));
                }
            }
        }
    return distance;
    }
    void print_Dijktra()
    {
        for(int i=0;i<distance.size();i++)
        {
            cout<<distance[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,5); g.addEdge(0,2,3); g.addEdge(1,2,2); g.addEdge(1,3,6); g.addEdge(2,3,7);
    g. addEdge(2,4,4); g.addEdge(2,5,2); g.addEdge(3,4,-1); g.addEdge(4,5,-2);
    g.Dijsktra(0,5);
    g.print_Dijktra();

}