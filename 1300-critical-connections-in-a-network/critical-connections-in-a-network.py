class Solution:
    def __init__(self):
        self.timer = 1
    def dfs(self,adj,time,lowestTime,visited,res,node,parent):
        visited[node] = 1
        self.timer+= 1
        time[node] = lowestTime[node] = self.timer

        for nei in adj[node]:
            if parent == nei: 
                continue

            if visited[nei] == 0:
                self.dfs(adj,time,lowestTime,visited,res,nei,node)
                
                lowestTime[node] = min(lowestTime[nei],lowestTime[node])
                
                if lowestTime[nei] > time[node]:
                        res.append([nei,node])
                
            else:
                lowestTime[node] = min(lowestTime[nei],lowestTime[node])



    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
      #creating the adj list
      adj=[[]for i in range(n)]  
      
      #generating the adj list for the graph
      for u,v in connections:
        adj[u].append(v)
        adj[v].append(u)


      time = [0]*n
      lowestTime = [0]*n
      visited = [0]*n
      res =[]

      self.dfs(adj,time,lowestTime,visited,res,0,-1) 
      
      return res