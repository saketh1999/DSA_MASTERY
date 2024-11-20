#User function Template for python3

from typing import List
import math


class Solution:

    def shortestPath(self, V: int, E: int, edges: List[List[int]]) -> List[int]:
        
        adjList ={i:[] for i in range(V)}
        visited = [0 for i in range(V)]
        
        #creating the adjlist
        for i in range(len(edges)):
            u,v,w = edges[i]
            adjList[u].append([v,w])
            
        
        #DFS toposort
        topo=[]
        def dfs_topo(start):
            visited[start]=1
            
            for v,w in adjList[start]:
                
                if visited[v]==0:
                    
                    dfs_topo(v)
            
            topo.append(start)
       
                  
        dfs_topo(0)

        
        distance = [-1 for i in range(V)]
        distance[0] = 0
        
        while topo:
            u = topo[-1]
            topo.pop()
            
            for nei in adjList[u]:
                v,w  = nei
                
                if(distance[u]+w < distance[v] or distance[v]==-1):
                    distance[v] = distance[u]+w
            
            
        
        return distance
        
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

from typing import List


class IntMatrix:

    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n, m = map(int, input().split())

        edges = IntMatrix().Input(m, 3)

        obj = Solution()
        res = obj.shortestPath(n, m, edges)

        IntArray().Print(res)
        print("~")

# } Driver Code Ends