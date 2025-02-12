class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        area=0
        for i in range(len(heights)):
            while stack and heights[stack[-1]]>heights[i]:
                nse = i
                index = stack.pop()
                pse=stack[-1] if stack else -1
                area=max(area,heights[index]*(nse-pse-1))
                print(heights[index]*(nse-pse-1),pse,nse)
            
            stack.append(i)

        while stack:
            nse = len(heights)
            index = stack[-1]
            stack.pop(-1)
            pse = stack[-1] if stack else -1
            area=max(area,heights[index]*(nse-pse-1))
        
        return area



            

