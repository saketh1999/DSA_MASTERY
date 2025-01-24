class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        isSafe = {}
        def dfs(i):
            if i in isSafe :
                return isSafe[i]
            
            isSafe[i] = False
            for nei in graph[i]:
                    if not dfs(nei):
                        return False
            isSafe[i] = True
            return True

        
        res = []
        for i in range(len(graph)):
            if dfs(i):
                res.append(i)
        
        return res

