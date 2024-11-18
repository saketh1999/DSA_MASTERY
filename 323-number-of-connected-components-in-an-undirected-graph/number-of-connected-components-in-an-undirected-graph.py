class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = [0 for i in range(n)]
        adjList = [[] for i in range(n)]
        
        for i in range(len(edges)):
            v1,v2 = edges[i]
            adjList[v1].append(v2)
            adjList[v2].append(v1)



        def dfs(start):
            visited[start]=1

            for n in adjList[start]:
                if visited[n]==0:
                    dfs(n)
            
        
        count = 0 
        for i in range(n):
            if visited[i] == 0:
                count+=1
                dfs(i)
        
        return count
