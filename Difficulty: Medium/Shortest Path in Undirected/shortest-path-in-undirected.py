#User function Template for python3
from collections import deque

class Solution:
    def shortestPath(self, edges, n, m, src):
        # code here
        dist = [-1 for i in range(n)]
        
        adjList = {i:[] for i in range(n)}
        
        visited = [0 for i in range(n)]
        
   
        for i in range(len(edges)):
            u,v=edges[i]
            adjList[u].append(v)
            adjList[v].append(u)
        
        q = deque()
        q.append(src)
        dist[src]=0
        visited[src]=1
        # print(adjList)
        
        while q:
            front = q[0]
            (q.popleft())
            
            
            for nei in adjList[front]:
                
                if visited[nei]==0:
                    # if dist[front]+1 < dist[nei] :
                        dist[nei]= dist[front]+1
                        # print(visited,nei)
                        visited[nei]=1
                        q.append(nei)
            #     if visited[nei] == 0:
            #         
            #             visited[nei]=1
            
          
        
        return dist

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = map(int, input().strip().split())
        edges=[]
        for i in range(m):
            li=list(map(int,input().split()))
            edges.append(li)
        src=int(input())
        ob = Solution()
        ans = ob.shortestPath(edges,n,m,src)
        for i in ans:
            print(i,end=" ")
        print()
        tc -= 1
# } Driver Code Ends