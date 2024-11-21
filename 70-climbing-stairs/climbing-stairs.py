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
        
        #Bottom Up Approach
        def climbTD(n):
            stairs = [-1]*(n+1)
            stairs[0]=1
            stairs[1]=1
            for i in range(2,n+1):
             stairs[i]=stairs[i-1]+stairs[i-2]

            
            return stairs[n]

        def climbTD_SpaceOptimized(n):

            prev2Stair = 1
            prevStair = 1
            for i in range(2,n+1):
             curr = prev2Stair+prevStair

             prev2Stair=prevStair
             prevStair=curr

            
            return prevStair
        
        return climbTD_SpaceOptimized(n)