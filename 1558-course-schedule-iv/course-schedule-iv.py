class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
       adjList = defaultdict(list)
       #creating the adj list
       for u,v in prerequisites:
        adjList[v].append(u)

       prereqMap = {} #map to store the required solution

       #dfs
       def dfs(crs):
        if crs not in prereqMap:
            prereqMap[crs] = set()
            for nei in adjList[crs]:
                prereqMap[crs] |= dfs(nei)
            prereqMap[crs].add(crs)
        return prereqMap[crs]

        
       #running dfs for each course
       for crs in range(numCourses):
        dfs(crs)
       
       res = [] 

       for u,v in queries:
        res.append(u in prereqMap[v])
       
       return res

    

    