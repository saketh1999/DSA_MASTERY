class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:

        adjList = [[] for i in range(n)]

        for i in range(n-1):
            adjList[i].append(i+1)
        
        def bfs():
            
            q= deque()
            visited = [0 for i in range(n)]
            q.append((0,0))

            while q:
                v,wt = q.popleft()
                if v == n-1:
                    return wt

                for nei in adjList[v]:
                    if visited[nei]==0:
                        visited[nei]=1
                        q.append((nei,wt+1))


        res = []    
        for u,v in queries:
            adjList[u].append(v)
            res.append(bfs())
        
        return res

