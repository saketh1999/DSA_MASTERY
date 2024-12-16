class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit=0
        prev_day_min = prices[0]
        for i in range(1,len(prices)):
            max_profit = max(max_profit,prices[i]-prev_day_min)
            prev_day_min = min(prev_day_min,prices[i])

        return max_profit

