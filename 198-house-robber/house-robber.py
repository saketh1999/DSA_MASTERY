class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        money = [-1] * (n+1)
        
        #Top Down
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
        
        #Bottom Up
        def robbery_TD(n):
            if n<0:
                return 0
            if len(nums)==1:
                return nums[0]
            money[0] = nums[0]
            money[1] = max(nums[0],nums[1])

            for i in range(2,n):
                money[i] = max(money[i-1],nums[i]+money[i-2])

            return money[n-1]

        return robbery_TD(n)