class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        money = [-1] * (n+1)

        def robbery(n):
            if n<0:
                return 0
        

            if money[n]!=-1:
                return money[n]

            #rob curr house
            x = nums[n] + robbery(n-2)

            #don't rob
            y = robbery(n-1)

            money[n] = max(x,y)
            return money[n]

        return max(robbery(n-1),robbery(n-2))