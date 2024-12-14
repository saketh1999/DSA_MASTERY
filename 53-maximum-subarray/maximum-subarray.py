class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_val = float(-inf)
        sum_so_far = 0
        for i in range(len(nums)):
            sum_so_far += nums[i]
            
            max_val = max(max_val,sum_so_far)
            if sum_so_far < 0:
                sum_so_far = 0
            
        
        return max_val