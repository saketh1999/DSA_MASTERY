class Solution:
    def rob(self, nums: List[int]) -> int:

       
        if len(nums)==1:
            return nums[0]
        #Bottom Up
        def robbery_TD(nums):
            n=len(nums)

            if n<=0:
                return 0
            if n==1:
                return nums[0]
            print(nums)
            prev2 = nums[0]
            prev = max(nums[0],nums[1])

            for i in range(2,n):
                curr = max(prev,nums[i]+prev2)
                prev2=prev
                prev=curr

            return prev


        arr1,arr2=nums[:-1],nums[1:]
       

        return max(robbery_TD(arr1),robbery_TD(arr2))