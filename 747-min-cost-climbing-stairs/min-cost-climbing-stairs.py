class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        dp = [-1] * (n+1)
        def helper(n):
            if n<0:
                return 0
            if dp[n]!=-1:
                return dp[n]
            
            dp[n] = cost[n]+ min(helper(n-1),helper(n-2))
            return dp[n]
        
        # return min(helper(n-1),helper(n-2))

        def helper_BU():
            dp[0]=cost[0]
            dp[1] = cost[1]
            for i in range(2,n):
                dp[i] = cost[i] + min(dp[i-1],dp[i-2])
            print(dp)
            return min(dp[n-1],dp[n-2])
        return helper_BU()