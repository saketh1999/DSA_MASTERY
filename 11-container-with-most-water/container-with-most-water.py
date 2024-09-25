class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l,r = 0,len(heights)-1
        res = 0
        while l < r:
            area = (r-l) * min(heights[l],heights[r])
            res = max(res,area)

            if heights[l] < heights[r]:
                l +=1
            elif heights[r] < heights[l]:
                r-=1
            
            elif heights[l] == heights[r]:
                if heights[l+1] > heights[r-1]:
                    l += 1
                else:    
                    r-=1

        return res