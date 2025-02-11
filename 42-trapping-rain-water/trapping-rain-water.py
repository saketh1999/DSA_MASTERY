class Solution:
    def trap(self, height: List[int]) -> int:
        left,right = 0,len(height)-1
        leftmax,rightmax = height[left],height[right]
        res = 0

        while left<right:
            if leftmax<rightmax:
                left+=1
                leftmax = max(height[left],leftmax)
                res+=abs(leftmax-height[left])
            else:
                right-=1
                rightmax=max(height[right],rightmax)
                res+=abs(rightmax-height[right])
        
        return res
            
