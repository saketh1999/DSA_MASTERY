#User function Template for python3
from typing import List
from collections import deque
class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        # code here
        q = deque()
        visited = [False]*len(adj)
        
        visited[0] = True
        q.append(0)
        
        ans = []
        
        while q:
            curr = q.popleft()
            ans.append(curr)
            
            for i in adj[curr]:
                if visited[i] is False:
                    visited[i] = True
                    q.append(i)
        return ans
        


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())  # Number of test cases
    for i in range(T):
        V = int(input())  # Number of vertices
        E = int(input())  # Number of edges
        adj = [[] for i in range(V)]  # Adjacency list
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)  # Undirected graph

        ob = Solution()
        ans = ob.bfsOfGraph(adj)
        print(" ".join(map(str, ans)))  # Print the BFS traversal result

# } Driver Code Ends