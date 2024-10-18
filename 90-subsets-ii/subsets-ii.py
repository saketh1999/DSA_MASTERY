class Solution:
    def rec_sub(self,nums,index,res,curr_res):
        if index >= len(nums):
            res.add(tuple(curr_res.copy()))
            return 
        
        
        #pick the index value
        curr_res.append(nums[index])
        self.rec_sub(nums,index+1,res,curr_res)

        #dont pick the index value
        curr_res.pop()  
        self.rec_sub(nums,index+1,res,curr_res)
        return
        
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res =set()
        nums.sort()

        self.rec_sub(nums,0,res,[])

        return list(res)