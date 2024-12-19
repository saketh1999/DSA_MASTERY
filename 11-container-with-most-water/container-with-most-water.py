class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r=0,len(height)-1
        max_area = 0
        while l<=r:

            area = (r-l) * min(height[l],height[r])
            max_area=max(area,max_area)

            if height[l]>height[r]:
                r-=1
            
            elif height[r]>height[l]:
                l+=1
            
            else:
                if height[r-1]>height[l-1]:
                    r-=1
                else:
                    l+=1
        return max_area

