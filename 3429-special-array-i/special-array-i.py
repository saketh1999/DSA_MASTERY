class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        if len(nums)==1:
            return True
        
        odd_or_even = nums[0]%2

        for i in range(1,len(nums)):
            if odd_or_even == nums[i]%2:
                return False
            odd_or_even = nums[i]%2
        
        return True