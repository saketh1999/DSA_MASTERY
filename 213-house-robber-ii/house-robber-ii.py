class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp1 = [-1]*(n+1)
        dp2 = [-1]*(n+1)

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

        arr1 = nums[1:n]
        arr2 = nums[0:n-1]

        return max(helper(n-2,arr1,dp1),helper(n-2,arr2,dp2))