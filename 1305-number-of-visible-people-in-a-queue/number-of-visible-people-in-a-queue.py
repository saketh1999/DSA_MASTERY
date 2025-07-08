class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        #next greatest element
        stack = []
        n= len(heights)
        sol = []
        for i in range(n-1,-1,-1):
            count=0
            while stack and heights[stack[-1]]<heights[i]:
                count+=1
                stack.pop()
            

            if stack:
                count+=1
            sol.append(count)
            stack.append(i)
        
        sol = sol[::-1]
        sol[-1]=0
        return sol
