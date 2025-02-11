class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = []
        res = []
        n = len(nums)

        for i in range(2*n-1,-1,-1):
            if not stack :
                res.append(-1)
            
            elif stack and stack[-1]>nums[i%n]:
                res.append(stack[-1])
            
            elif stack and stack[-1]<=nums[i%n]:
                while stack and stack[-1]<=nums[i%n]:
                    stack.pop(-1)
                
                if not stack:
                    res.append(-1)
                
                else:
                    res.append(stack[-1])

            stack.append(nums[i%n])

        res = res[::-1]
        sol=res[:n]

        return sol
