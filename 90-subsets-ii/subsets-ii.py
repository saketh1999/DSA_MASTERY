class Solution:
    def rec_sub(self,nums,index,res,curr_res):
        if index >= len(nums):
            # curr_res.sort()
            res.append(curr_res.copy())

            return 
        
        
        #pick the index value
        curr_res.append(nums[index])
        self.rec_sub(nums,index+1,res,curr_res)

        #dont pick the index value
        curr_res.pop()  
        self.rec_sub(nums,index+1,res,curr_res)
        return
        
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res =[]
        final_res = []
        myTempSet = set()
        nums.sort()

        self.rec_sub(nums,0,res,[])

        for r in res:
            myTempSet.add(tuple(r))
        for x in myTempSet:
            final_res.append(x)



        return final_res