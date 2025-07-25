class Solution:
    def fib(self, n: int) -> int:
        #recursion + memoization
    
        def recurr(n):
            if n<=0:
                return 0
            elif n==1:
                return 1
            if dp[n]!=-1:
                return dp[n]

            dp[n] = recurr(n-1) + recurr(n-2)
            return dp[n]
            
        if n==0:
            return 0
        if n==1:
            return 1
        dp = [-1]*(n+1)
        recurr(n)
        return dp[n]