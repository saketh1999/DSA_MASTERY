class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = []
        def helper(res):
            
            if len(res) == len(nums):
                temp = "".join(res)
                if temp not in nums:
                    return temp

                else:
                    return None
           
            res.append("1")
            ans = helper(res)
            if ans:
                return ans

            res.pop(-1)

            res.append("0")
            ans = helper(res)
            if ans:
                return ans
            res.pop(-1)


        return helper(res)