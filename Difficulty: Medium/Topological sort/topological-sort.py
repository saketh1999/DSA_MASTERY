class Solution:
    
    #Function to return list containing vertices in Topological order.
    def topologicalSort(self,adj):
        topo = []
        
        visited = [0 for _ in range(len(adj)) ]
        
        def dfs(start):
            visited[start]=1
            
            for n in adj[start]:
                if visited[n]==0:
                    dfs(n)
            
            topo.append(start)
        
        for i in range(len(adj)):
            if visited[i] == 0 :
                dfs(i)
        
        topo.reverse()
        
        return topo
        
        # Code here



#{ 
 # Driver Code Starts
# Driver Program

import sys

sys.setrecursionlimit(10**6)


def check(graph, N, res):
    if N != len(res):
        return False
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        e, N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]

        for i in range(e):
            u, v = map(int, input().split())
            adj[u].append(v)

        ob = Solution()

        res = ob.topologicalSort(adj)

        if check(adj, N, res):
            print(1)
        else:
            print(0)
        print("~")
# Contributed By: Harshit Sidhwa

# } Driver Code Ends