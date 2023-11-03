#include <iostream>
#include <map>
#include <vector>
#include <list>
#include<queue>
using namespace std;

int diameter_helper(map<int,list<int> > &adjlist, vector<int> distance,vector<int> visited, int start)
{
    queue<int> q;
    
       
            q.push(start);
            visited[start]=1;

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                for(auto x : adjlist[front])
                {
                    if(!visited[x])
                    {
                        q.push(x);
                        visited[x]=1;

                        distance[x] = distance[front]+1;
                    }
                }
            }
            
        
    
    int ind_max=0,max_ele=distance[0];
    for(int i=1;i<distance.size();i++)
    {
        if(distance[i]>max_ele)
        {ind_max=i;
        max_ele=distance[i];
        }

    }
    return ind_max;

}
int diameter(map<int,list<int> > &adjlist)
{
    vector<int> distance(adjlist.size(),0); //Initializing all the values to 0
    vector<int> visited(adjlist.size(),0);
    int a =diameter_helper(adjlist,distance,visited,0); //distance from any vertice to another a
    int b =diameter_helper(adjlist,distance,visited,a);//distance from a to b 
    //in the above two func_calls we are returning the index values of the max distance we found in each case

    //finally we will return the max distance which is also the diameter of the N array tree.
    return distance[b]; 
}