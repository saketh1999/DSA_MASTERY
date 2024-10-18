class Solution:
    def rec_sub(self,nums,index,res,curr_res):
        if index >= len(nums):
            res.append(curr_res.copy())

            return 
        
        
        #pick the index value
        curr_res.append(nums[index])
        self.rec_sub(nums,index+1,res,curr_res)

        #dont pick the index value
        curr_res.pop()  
        self.rec_sub(nums,index+1,res,curr_res)
        return
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res =[]
        self.rec_sub(nums,0,res,[])
        return res