class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        row = len(rooms)
        col = len(rooms[0])
        visited = set()
        q = deque()
        dist = 1


        for i in range(row):
            for j in range(col):
                if rooms[i][j] == 0:
                    q.append([i,j])
                    visited.add((i,j))

        
        
        distances = [[0,1],[1,0],[0,-1],[-1,0]]
      
        while q:
            size_q = len(q)

            for i in range(size_q):
                r,c = q[0]
                q.popleft()

                for dr,dc in distances:
                    nr,nc = r+dr,c+dc
                    if nr<row and nr>=0 and nc<col and nc>=0 and (nr,nc) not in visited:
                        if rooms[nr][nc]!= -1:
                            q.append([nr,nc])
                            visited.add((nr,nc))
                            rooms[nr][nc] = min(rooms[nr][nc],dist)
                    
            dist+=1
                

        
        