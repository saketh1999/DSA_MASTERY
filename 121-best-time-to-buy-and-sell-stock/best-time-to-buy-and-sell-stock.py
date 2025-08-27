class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # max_profit=0
        # prev_day_min = prices[0]
        # for i in range(1,len(prices)):
        #     max_profit = max(max_profit,prices[i]-prev_day_min)
        #     prev_day_min = min(prev_day_min,prices[i])

        # return max_profit
        stack = []
        max_profit=0
        for i in range(len(prices)-1,-1,-1):
            if not stack:
                stack.append(prices[i])
                # print("here",stack)
            else:
                if stack[-1] > prices[i]:
                    max_profit = max(max_profit,stack[-1]-prices[i])
                else:
                    stack.pop()
                    stack.append(prices[i])
                # print(stack)
        return max_profit

