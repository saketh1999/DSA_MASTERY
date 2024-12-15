class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [ [-1 for _ in range(len(grid[0])+1) ] for _ in range(len(grid)) ]
        def pathf(i,j):

            if i>=len(grid) or i<0 or j>=len(grid[0]) or j<0:
                return 10e7
            if i==len(grid)-1 and j==len(grid[0])-1:
                return grid[i][j]

            if dp[i][j]!=-1:
                return dp[i][j]

            dp[i][j] = min(pathf(i+1,j),pathf(i,j+1)) + grid[i][j]


            return dp[i][j]
        
        return pathf(0,0)