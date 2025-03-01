class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [-1]*(len(nums)+1)
        n = len(nums)
        def helper(i):
            if i<0:
                return 0
            
            if dp[i]!=-1:
                return dp[i]

            take = nums[i] + helper(i-2)
            dont_take = helper(i-1)
            dp[i] = max(take,dont_take)
        
            return dp[i]
        # return max(helper(n-1) , helper(n-2))

        def helper_bt_up():
           
            if n == 1:
                return nums[0]
            
            dp[0] = nums[0]


            for i in range(1,n):
                take = nums[i] 
                if i>1:
                    take+=dp[i-2]
                dont_take = dp[i-1]
                dp[i] = max(take,dont_take)
            
            return dp[n-1]
        return helper_bt_up()