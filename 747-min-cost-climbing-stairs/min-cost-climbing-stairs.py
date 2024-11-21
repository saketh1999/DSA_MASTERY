class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        stair_cost = [-1]*(n+1)
        #Bottom up
        def climb(n):
            if n == 0:
                return cost[0]

            if n == 1:
                return cost[1]

            if stair_cost[n]!=-1:
                return stair_cost[n]

            stair_cost[n] = cost[n] + min(climb(n-1),climb(n-2))
            return stair_cost[n]
        
        #Top Down
        def climb_TD(n):
            stair_cost[0] = cost[0]
            stair_cost[1] = cost[1]
            
            print(stair_cost)
            for i in range(2,n):

                stair_cost[i] = min(stair_cost[i-1],stair_cost[i-2]) + cost[i]

            return min(stair_cost[n-1],stair_cost[n-2])
        return climb_TD(n)