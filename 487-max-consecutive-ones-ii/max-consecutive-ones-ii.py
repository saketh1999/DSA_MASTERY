class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left,right = 0,0
        count = 0
        max_len = 0
        while right < len(nums):
            if nums[right]==0:
                count+=1
            
                while count>1 and left<=right:
                    if nums[left] == 0:
                        count-=1
                    left+=1
                max_len = max(max_len,right-left+1)
            else:
                
                max_len = max(max_len,right-left+1)
            
            right+=1
        
        return max_len

                

            
                