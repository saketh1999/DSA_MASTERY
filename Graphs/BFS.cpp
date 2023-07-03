/*This code is for BFS on graphs,
 * https://www.youtube.com/watch?v=uQtX6dfbk0M&list=RDCMUCICWIYEx2mo4wYZzLwJ7wVw&start_radio=1
 */
#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
template <typename T>

class graph {

  map<T, list<T> > adjlist;

public:
  void add_edge(T v1, T v2) {
    adjlist[v1].push_back(v2);
    adjlist[v2].push_back(v1);
  }
  void bfs_traversal(T src) // src -> is the start node/vertix
  {
    queue<T> V_q; 
    map<T, bool> V_mp;// visited vertix queue

    V_q.push(src);
    V_mp[src] = true;

    while (!V_q.empty()) {
      T vertix = V_q.front(); // Checking the element in the Queue
      V_q.pop();              // poping it since its now visited
      cout << vertix << " ";
      for (auto nbr : adjlist[vertix]) {
        if (!V_mp[nbr])//if the next vertix is not visited , only then add to queue
        {
          V_q.push(nbr);
          V_mp[nbr] = true;
        }
      }
    }
  }
};

int main() {

    /*Here you can see the power of templates in C++ */
    /*ALL the 'T' will be replaced by int/string depending on graph declaration */
//   graph <string> g;
//   g.add_edge("A", "B");
//   g.add_edge("B", "D");
//   g.add_edge("A", "C");
//   g.add_edge("C", "D");
//   g.add_edge("A", "D");
//   g.bfs_traversal("A");

   graph <int> g;
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,3);
    g.add_edge(1,2);
    g.bfs_traversal(0);
  return 1;
}