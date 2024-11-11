class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        
        left,right = 0,0
        max_to_left_arr = [0]*len(nums)
        
        max_ele = float(-inf)
        for i in range(len(nums)-1,-1,-1):
            max_ele = max(max_ele,nums[i])
            max_to_left_arr[i] = max_ele
        


        max_ramp_width = float(-inf)

        while right<len(nums):
            while nums[left] > max_to_left_arr[right]:
                left+=1

          
            max_ramp_width = max(max_ramp_width,right-left)

            right+=1

        return max_ramp_width
