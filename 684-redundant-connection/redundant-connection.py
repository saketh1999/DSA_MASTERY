class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = [i for i in range(n+1)]
        rank = [0 for i in range(n+1)]

        def find(node):
            p = parent[node]
            while p!= parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]
            return p
        
        def union(node1,node2):
            p1,p2 = find(node1),find(node2)

            if p1 == p2:
                return False
            
            if rank[p1] > rank[p2]:
                parent[p2]=p1
            elif rank[p1] < rank[p2]:
                parent[p1]=p2
            else:
                parent[p1]=p2
                rank[p2]+=1
            return True
        
        for u,v in edges:
            if  union(u,v) == False:
                return [u,v]