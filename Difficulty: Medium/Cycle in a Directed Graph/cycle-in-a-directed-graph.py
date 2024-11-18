#User function Template for python3
from typing import List

class Solution:
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V : int , adj : List[List[int]]) -> bool :
        # code here
        vertices = len(adj)
        path_visited = [0 for _ in range(len(adj))]
        visited = [0 for _ in range(len(adj))]
        
        def dfs_cycle(start):
            visited[start] = 1
            path_visited[start] = 1
            
            for nei in adj[start]:
                if visited[nei] ==1 and path_visited[nei]==1:
                    return True
                if dfs_cycle(nei):
                    return True
            
            path_visited[start]=0
            
            return False
            
        
        
        for i in range(vertices):
            if dfs_cycle(i):
                return True
        
        return False
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V, E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a, b = map(int, input().strip().split())
            adj[a].append(b)
        ob = Solution()

        if ob.isCyclic(V, adj):
            print(1)
        else:
            print(0)

        print("~")
# } Driver Code Ends