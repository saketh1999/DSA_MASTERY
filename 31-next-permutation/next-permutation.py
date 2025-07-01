class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return nums
        dip = -1
        for i in range(len(nums)-2,-1,-1):
            if nums[i+1] > nums[i]:
                dip=i
                break
        if dip == -1:
            nums.reverse()
            return nums

       
        for i in range(len(nums)-1,-1,-1):
            if nums[dip]<nums[i]:
                print(nums[i])
                nums[dip],nums[i] = nums[i],nums[dip]
                break
        print(nums)
        nums[dip+1:] = nums[dip+1:][::-1]
        return nums
        