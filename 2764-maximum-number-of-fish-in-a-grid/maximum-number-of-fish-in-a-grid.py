class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        #connected compoents
        row = len(grid)
        col = len(grid[0])
        directions = [(0,1),(1,0),(0,-1),(-1,0)]

        def dfs(i,j,sum):
            
            sum+=grid[i][j]
         
            visited.add((i,j))

            for r,c in directions:
                nr,nc = r+i,c+j
                if nr>=0 and nr<row and nc>=0 and nc<col and (nr,nc) not in visited and grid[nr][nc]!=0:
                    sum = dfs(nr,nc,sum)
            
            return sum


                                


        visited = set()
        res = float('-inf')
        for i in range(row):
            for j in range(col):
                if (i,j) not in visited and grid[i][j]!=0:
                    sum = 0
                    out = dfs(i,j,sum)
                    res = max(res,out)

        if res>0:
            
            return res

        return 0