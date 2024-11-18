from collections import deque

class Solution:
    
    #Function to return list containing vertices in Topological order.
    def topologicalSort(self,adj):
        # Code here
        topo = []
        indegree = [0 for i in range(len(adj))]
        
        q = deque()
        
        #creating an indegree array
        for i in range(len(adj)):
            for n in adj[i]:
                indegree[n]+=1
                
        #adding all the vertices with indegree = 0. to the queue
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)

        while q:
                front = q[0]
                q.popleft()
                
                topo.append(front)
                
                for n in adj[front]:
                    indegree[n] -=1
                    
                    if indegree[n] == 0:
                        q.append(n)
        
        
        return topo



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