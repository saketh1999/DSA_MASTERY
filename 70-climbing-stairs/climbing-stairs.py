class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0]*(n+1)
        def helper(n):
            if n==0 or n==1:
                return 1
            if dp[n]:
                return dp[n]

            dp[n] = helper(n-1)+helper(n-2)
            return dp[n]

        return helper(n)