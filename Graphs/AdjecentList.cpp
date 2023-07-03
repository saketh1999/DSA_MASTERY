#include <list>
#include<iostream>
//NOTE: This code will only work for the case when the verticles are starting from 0 and are continuous
using namespace std;
class Graph
{
    int V ; 
    list<int> *l; //creating a pointed to 
    public: 

    //Constructor
    Graph (int V)
    {
        this->V=V; //Storing the number of vetices, this->V points to the member variable
        l = new list<int> [V]; //each list is of size V, *l is now converted to an array of list 
    }
    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print_g()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Vertix "<<i<<" -> " ;
            for( list<int>::iterator j=l[i].begin(); j!=l[i].end();j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,3);
    g.add_edge(1,2);
    g.print_g();
    return 1;
}