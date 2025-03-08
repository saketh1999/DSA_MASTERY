class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        i,j=0,len(nums)-1 #traverse the arr
        i2,j2=0,len(nums)-1 # pointer to add the numbers to the new arr
        res = [0]*len(nums)

        while i <= len(nums)-1:
            if nums[i]<pivot:
                res[i2] = nums[i]
                i2+=1
            if nums[j]>pivot:
                res[j2] = nums[j]
                j2-=1
                
            i,j=i+1,j-1
        
        while i2<=j2:
            res[i2]=pivot
            i2+=1
        
        return res
