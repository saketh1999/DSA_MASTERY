from typing import List
from collections import deque
class Solution:
    #Function to detect cycle in an undirected graph.
	def isCycle(self, V: int, adj: List[List[int]]) -> bool:
		#Code here
		visited = [0 for _ in range(V)]
		                
		def dfs_cycle_detection(node,parent):
		    
		    visited[node] = 1
		    
		    for n in adj[node]:
		        if visited[n] == 0:
		            if dfs_cycle_detection(n,node):
		                return True
		                
		        elif parent!=n:
		            
		            return True
		            
		    return False
		                
		for i in range(V):
		     if visited[i]==0:
		         if dfs_cycle_detection(i,-1):
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