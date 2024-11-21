class Solution:
    def climbStairs(self, n: int) -> int:
        #Top Down Approach
        stairs = [-1]*(n+1)

        def climb(n):
            if n == 0:
                return 1
            if n==1:
                return 1

            if stairs[n]!=-1:
                return stairs[n]
            stairs[n] = climb(n-1)+climb(n-2)
            return stairs[n]
        
        return climb(n)