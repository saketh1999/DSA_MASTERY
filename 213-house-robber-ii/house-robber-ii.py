class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1]*(n+1)

        if n == 1:
            return nums[0]

        def helper(h,arr,dp):

            if h<0:
                return 0

    
            if dp[h]!=-1:
                return dp[h]

            pick = arr[h] + helper(h-2,arr,dp)
            d_pick = helper(h-1,arr,dp)

            dp[h] = max(pick,d_pick)
            return dp[h]

        # arr1 = nums[1:n]
        # arr2 = nums[0:n-1]

        max1 = helper(n-2,nums[1:n],dp)
        dp = [-1]*(n+1)
        max2 = helper(n-2,nums[0:n-1],dp)

        return max(max1,max2)