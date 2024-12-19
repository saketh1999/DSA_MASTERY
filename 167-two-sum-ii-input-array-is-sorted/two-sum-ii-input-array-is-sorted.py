class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        for i in range(len(nums)):
            l,r=i+1,len(nums)-1
            my_t = target-nums[i]
            while l<=r:
                mid = (l+r)//2
                if nums[mid]==my_t:
                    return [i+1,mid+1]
                elif nums[mid]>my_t:
                    r=mid-1
                else:
                    l=mid+1
        