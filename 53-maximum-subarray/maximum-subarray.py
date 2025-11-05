class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        i = 0
        j = 0
        maxsum = float('-inf')
        currsum = float('-inf')

        while i < len(nums):
            currsum += nums[i]
            if currsum <= nums[i]:
                currsum = nums[i]
            i += 1
            maxsum = max(maxsum,currsum)

        return maxsum

            
            
            
