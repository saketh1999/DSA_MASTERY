class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [[-1 for i in range(n)]for j in range(m)]

        def helper(i,j):
            # print(i,j)
            if i<0 or j<0: #out of bounds
                return float('inf')
            
            if i==0 and j==0:
                dp[i][j]=grid[i][j]
                return grid[i][j]

            if dp[i][j]!=-1:
                return dp[i][j]
            up =  helper(i-1,j) 
            left = helper(i,j-1)

            

            # print(up,left,grid[i][j]+up,grid[i][j]+left,i,j)
            dp[i][j] = min(up+grid[i][j],left+grid[i][j])
            
            return dp[i][j]
            
        ans = float('inf')
        ans = min(helper(m-1,n-1),ans)
        # print(dp)
           

        return ans