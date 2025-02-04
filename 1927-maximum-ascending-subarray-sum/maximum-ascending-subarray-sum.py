class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        
        if len(nums) == 1:
            return nums[0]
        max_sum = nums[0]
        sum_var = nums[0]


        for i in range(1,len(nums)):
            if nums[i]<=nums[i-1]:
                # print(nums[i],nums[i-1])
                sum_var = nums[i]
                
            else:
                sum_var += nums[i]
               

            max_sum = max(max_sum,sum_var)
            

        return max_sum
