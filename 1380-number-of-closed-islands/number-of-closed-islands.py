class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        visited = [[False for c in range(col)]for r in range(row)]


        def dfs(r,c):
            if r<0 or r>=row or c<0 or c>=col:
                return False
            
            if visited[r][c] or grid[r][c]==1:
                return True
            
            visited[r][c] = True
            is_closed = True
            directions = [(1,0),(0,1),(-1,0),(0,-1)]
            for i,j in directions:
                nr = r+i
                nc = c+j
                if not dfs(nr,nc):
                    is_closed = False
            return is_closed

        count=0
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 0 and not visited[r][c] and dfs(r,c):

                        count+=1
        return count
