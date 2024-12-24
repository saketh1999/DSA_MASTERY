class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxArea = 0
        for ind, height in  enumerate(heights):
            start = ind
            while stack and heights[ind] <= stack[-1][1]:
                i,h = stack.pop(-1)
                maxArea = max(maxArea,h*(ind-i))
                start = i
            stack.append([start,height])
        
        for ind,height in stack:
            maxArea = max(maxArea,height*(len(heights)-ind))
        
        return maxArea

                