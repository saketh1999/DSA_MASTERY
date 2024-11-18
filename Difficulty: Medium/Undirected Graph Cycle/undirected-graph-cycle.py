from typing import List
from collections import deque
class Solution:
    #Function to detect cycle in an undirected graph.
	def isCycle(self, V: int, adj: List[List[int]]) -> bool:
		#Code here
		visited = [0 for _ in range(V+1)]
		
		
		def bfs_cycle_detection(node):
		    q = deque()
		    q.append((node,-1))
		    visited[node]=1
		    
		    
		    while q:
		        curr,parent = q[0]
		        q.popleft()
		        
		        for n in adj[curr]:
		            if visited[n] == 0:
		                visited[n]=1
		                q.append((n,curr))
		                
		            elif parent!= n:
		                return True
		                
		for i in range(V):
		     if visited[i]==0:
		         if bfs_cycle_detection(i):
		             return True
		        
		    
        return False
    
#{ 
 # Driver Code Starts

if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.isCycle(V, adj)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends