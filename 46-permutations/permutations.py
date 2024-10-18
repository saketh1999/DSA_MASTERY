class Solution:
    def permutation(self,nums,index,res):
        if index == len(nums)-1:
            res.append(nums.copy())
            return
        
        for i in range(index,len(nums),1):
            
            nums[index],nums[i] = nums[i],nums[index]
            self.permutation(nums,index+1,res)
            nums[index],nums[i] = nums[i],nums[index]

        return
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.permutation(nums,0,res)

        return res