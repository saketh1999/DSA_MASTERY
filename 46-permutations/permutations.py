class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res=set()
        def permutation(ind):
            if ind >=len(nums)-1:
                copy=nums.copy()
                res.add(tuple(copy))
                return
            
            for i in range(len(nums)):
                
                nums[ind],nums[i]=nums[i],nums[ind]
                permutation(ind+1)
                nums[i],nums[ind]=nums[ind],nums[i]

        permutation(0)
        return list(res)