#{ 
 # Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys
import heapq
from typing import List, Tuple


# } Driver Code Ends

import heapq
import math
class Solution:
    # Function to find the shortest distance of all the vertices
    # from the source vertex src.
    def dijkstra(self, adj: List[List[Tuple[int, int]]], src: int) -> List[int]:
        # Your code here
        size = len(adj)
        
        
        dist = [math.inf for i in range(size)]
        
        
        q = []
        
        heapq.heappush(q,(0,src))
        dist[src]=0
        

        
        while q:

            
            wi,u = heapq.heappop(q)
            
        
            
            
            
            for nei in adj[u]:
                v,w = nei

                
                if dist[u]+w < dist[v]:
                    dist[v] = dist[u]+w
                    heapq.heappush(q,(dist[v],v))
        
        return dist
                    
                

#{ 
 # Driver Code Starts.

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V, E = map(int, input().strip().split())
        adj = [[] for _ in range(V)]
        for _ in range(E):
            u, v, w = map(int, input().strip().split())
            adj[u].append((v, w))
            adj[v].append((u, w))
        src = int(input())
        ob = Solution()

        res = ob.dijkstra(adj, src)
        for i in res:
            print(i, end=" ")
        print()
        print("~")
# } Driver Code Ends