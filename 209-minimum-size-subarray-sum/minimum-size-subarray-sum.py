class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left,right = 0,0
        min_len = float("inf")
        pre_sum =0
        while right<len(nums):
            pre_sum+=nums[right]
            
            if pre_sum>=target:
                min_len = min(min_len,right-left+1)

            while pre_sum>target and left<=right:
                pre_sum-=nums[left]
                left+=1
                if pre_sum>=target:
                    min_len = min(min_len,right-left+1)
            right+=1
            
        return min_len if min_len != float('inf') else 0


