#User function Template for python3

class Solution:
    
    def dfs_trav(self,stack,adj,node,visited):
        visited[node]=1
        
        for nei in adj[node]:
            if visited[nei]==0:
                self.dfs_trav(stack,adj,nei,visited)
        
        stack.append(node)
        
    def dfs(self,adjT,visited,node):
        visited[node]=1
        
        for nei in adjT[node]:
            if visited[nei] == 0:
                
                self.dfs(adjT,visited,nei)
        
        
    #Function to find number of strongly connected components in the graph.
    def kosaraju(self, V, adj):
        # code here
        visited = [0]*V
        
        finish_time_stack = []
        for i in range(V):
            if visited[i]==0:
                self.dfs_trav(finish_time_stack,adj,i,visited)
        
        
        #reversing the edges in the graph
        adjT = [[] for i in range(V)]
        for i in range(V):
            visited[i]=0
            for nei in adj[i]:
                adjT[nei].append(i)
        
        
        count=0
        while finish_time_stack:
            top = finish_time_stack[-1]
            finish_time_stack.pop()
            
            
            
            if visited[top]==0:
                    count +=1
                    self.dfs(adjT,visited,top)
            
                
                
        
        
        return count
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import OrderedDict 
import sys 

sys.setrecursionlimit(10**6) 
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
        ob = Solution()
        
        print(ob.kosaraju(V, adj))
        print("~")
# } Driver Code Ends