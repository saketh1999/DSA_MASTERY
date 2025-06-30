class Solution:
    def rec_sub(self,nums,index,res,curr_res,target):

        if target == 0:
            res.add(tuple(curr_res.copy()))
            return 
        if target < 0:
            return
        if index >= len(nums):
            return
        for i in range(index,len(nums),1):
            if i > index and nums[i]==nums[i-1]: #if the two adj values are same don't pick
                continue

            curr_res.append(nums[i])
            self.rec_sub(nums,i+1,res,curr_res,target-nums[i])
            curr_res.pop()  
           
        
        return
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res=set()
        candidates.sort()
        self.rec_sub(candidates,0,res,[],target)
        return list(res)