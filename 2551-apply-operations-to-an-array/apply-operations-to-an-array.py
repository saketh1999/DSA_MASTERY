class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            if i+1<len(nums):
                if nums[i] == nums[i+1]:
                    nums[i]*=2
                    nums[i+1]=0
        prev_zero_ind = float('inf')
        for i in range(len(nums)):
            if nums[i] == 0:
                prev_zero_ind = min(prev_zero_ind,i)
            elif nums[i]!=0 and prev_zero_ind!=float('inf'):
                nums[i],nums[prev_zero_ind] = nums[prev_zero_ind],nums[i]
                while nums[prev_zero_ind]!=0:
                    prev_zero_ind+=1
        
        return nums