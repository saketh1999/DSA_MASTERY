class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])

        row_sum = [0]*len(grid)
        col_sum = [0]*len(grid[0])

        for i in range(row):
            for j in range(col):
                row_sum[i]+=grid[i][j]
                col_sum[j]+=grid[i][j]
        res = 0
        for i in range(row):
            for j in range(col):
               if grid[i][j] and max(row_sum[i],col_sum[j])>1:
                    res+=1
        return res