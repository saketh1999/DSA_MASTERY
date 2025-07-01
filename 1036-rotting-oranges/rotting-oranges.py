class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])


        q = deque()
        time,fresh_oranges = 0,0


        for i in range(row):
            for j in range(col):
                if grid[i][j]==1:
                    fresh_oranges+=1

                if grid[i][j] == 2:
                    q.append([i,j])

        directions = [[1,0],[-1,0],[0,1],[0,-1]]

        while q and fresh_oranges>0:

            size_q = len(q)
            for i in range(size_q):
                
                r,c = q[0]
                q.popleft()

                for dr,dc in directions:
                    nr,nc = r+dr,c+dc

                    if nr>=0 and nr<row and nc>=0 and nc<col:
                        if grid[nr][nc]==1:
                            grid[nr][nc]=2
                            q.append([nr,nc])
                            fresh_oranges-=1
            time+=1

        if fresh_oranges:
            return -1
        else:
            return time            






