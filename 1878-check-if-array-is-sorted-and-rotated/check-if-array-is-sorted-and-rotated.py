class Solution:
    def check(self, nums: List[int]) -> bool:
        count = 0
        for i in range(1,len(nums)):
            if nums[i-1]>nums[i]:
                count+=1
        
        if nums[0] < nums[len(nums)-1]:
            count+=1
        
        return count<=1
        
            
