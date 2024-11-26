#User function Template for python3
from typing import List
import heapq
class Solution:
    
    #Function to find sum of weights of edges of the Minimum Spanning Tree.
    def spanningTree(self, V: int, adj: List[List[int]]) -> int:
        #code here
        visited = [0]*V
        q = []
        heapq.heappush(q,(0,0))
        mst=0
        
        while q:
            wt,node = q[0]
            heapq.heappop(q)
            
            if visited[node]==1:
                continue
            
            visited[node]=1
            mst+=wt
            
            for v,w in adj[node]:
                
                if visited[v]==0:
                    heapq.heappush(q,(w,v))
        
        return mst


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
from typing import List

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V, E = map(int, input().strip().split())
        adj = [[] for i in range(V)]
        for i in range(E):
            u, v, w = map(int, input().strip().split())
            adj[u].append([v, w])
            adj[v].append([u, w])
        ob = Solution()

        print(ob.spanningTree(V, adj))
        print("~")

# } Driver Code Ends