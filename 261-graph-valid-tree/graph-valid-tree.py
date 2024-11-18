class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) < n-1:
            return False

        adj = [[] for i in range(n)]

        for i in range(len(edges)):
            v1,v2 = edges[i]
            adj[v1].append(v2)
            adj[v2].append(v1)

        
        visited = [0 for i in range(n)]
        #check for cycle in the graph

        def dfs_cycle(v,parent):
            visited[v]=1

            for n in adj[v]:
                if visited[n]==0:
                    if dfs_cycle(n,v):
                        return True
                    
                elif parent != n:
                    return True
            
            return False
        
        for i in range(n):
            if visited[i]==0:
                if dfs_cycle(i,-1):

                    return False
        
        return True
                
                