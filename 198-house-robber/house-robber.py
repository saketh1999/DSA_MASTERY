class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [-1]*(len(nums)+1)
        n = len(nums)
        def helper(i):
            if i<0:
                return 0

            # if i==0 or i==1:
            #     return nums[i]
            
            if dp[i]!=-1:
                return dp[i]
            take = nums[i] + helper(i-2)
            dont_take = helper(i-1)
            dp[i] = max(take,dont_take)
        
            return dp[i]
        return max(helper(n-1) , helper(n-2))