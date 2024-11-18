class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        adj = [[] for _ in range(numCourses)]

        for i in range(len(prerequisites)):
            v1,v2 = prerequisites[i]
            adj[v1].append(v2)
        
        q=deque()

        indegree = [0 for _ in range(numCourses)]

        for i in range(numCourses):
            for n in adj[i]:
                indegree[n]+=1
        
        for i in range(len(indegree)):
            if indegree[i]==0:
                q.append(i)

        topo = []
        while q:
            front = q[0]
            q.popleft()
            topo.append(front)

            for n in adj[front]:
                indegree[n]-=1
                if indegree[n]==0:
                    q.append(n)

        
        if numCourses == len(topo):
            return True
        return False


