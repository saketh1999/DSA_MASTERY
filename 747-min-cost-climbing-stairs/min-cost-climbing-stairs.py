class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        stair_cost = [-1]*(n+1)
        def climb(n):
            if n == 0:
                return cost[0]

            if n == 1:
                return cost[1]

            if stair_cost[n]!=-1:
                return stair_cost[n]

            stair_cost[n] = cost[n] + min(climb(n-1),climb(n-2))
            return stair_cost[n]
        
        return min(climb(n-1),climb(n-2))