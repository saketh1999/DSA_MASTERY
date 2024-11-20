#User function Template for python3

class Solution:
    '''
    Function to implement Bellman Ford
    V: nodes in graph
    edges: adjacency list for the graph
    src: source vertex
    '''
    def bellmanFord(self, V, edges, src):
    
        distance = [int(1e8)] * V
        
        distance[src]=0
        
        for i in range(V-1):
            for u,v,wt in edges:
                if (distance[u]!=int(1e8) and distance[u]+wt<distance[v]):
                    distance[v] = distance[u]+wt
                

        for u,v,wt in edges:
                if (distance[u]!=int(1e8) and distance[u]+wt<distance[v]):
                    distance[v] = distance[u]+wt
                
                    return {-1}
        
        return distance
            
#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V, E = map(int, input().strip().split())
        edges = []
        for i in range(E):
            u, v, w = map(int, input().strip().split())
            edges.append([u, v, w])
        S = int(input())
        ob = Solution()

        res = ob.bellmanFord(V, edges, S)
        for i in res:
            print(i, end=" ")
        print()

# } Driver Code Ends