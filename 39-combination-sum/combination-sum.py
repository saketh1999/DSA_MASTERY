class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def sum(index,target,temp):
            nonlocal res

            if target == 0:
                if temp not in res:
                    res.append(temp.copy())
                return
            
            if target <0:
                return
            
            for i in range(index,len(candidates)):
                temp.append(candidates[i])
                sum(i,target-candidates[i],temp)
                temp.pop()


        temp = []
        curr_sum = 0 
        sum(0,target,temp)
        return res
