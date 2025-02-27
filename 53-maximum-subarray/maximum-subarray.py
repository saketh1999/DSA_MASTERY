class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = float('-inf')
        curr_sum = 0
        for x in nums:
            curr_sum+=x
            max_sum = max(max_sum,curr_sum)
            if curr_sum<0:
                curr_sum=0
            
            

        return max_sum