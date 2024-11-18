class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        vertices = len(graph)
        colored = [-1 for _ in range(vertices)]

        def bfs(start):
            q = deque()
            q.append(start)

            colored[start] = 0

            while q:
                front = q[0]
                q.popleft()

                for nei in graph[front]:
                    if colored[nei] == colored[front]:
                        return False
                    
                    if colored[nei]==-1:
                        colored[nei] = not colored[front]
                        q.append(nei)
            
            return True
        
        for i in range(vertices):
            if colored[i]==-1:
               if bfs(i) == False:
                return False
        return True

