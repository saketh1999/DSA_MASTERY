class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        if len(nums)==1:
            return 0

        while l<=r:
            mid = (l+r)//2
            print('mid',mid)

            if mid ==0 and mid+1<=len(nums)-1:
                print("hi1")
                print(mid)
                print(nums[mid+1],nums[mid])
                if nums[mid+1]<nums[mid] :
                    
                    return mid
                else:
                    print("hrr")
                    l=mid+1

            elif mid == len(nums)-1 and len(nums)>0:
                print("hi2")
                if nums[mid-1]<nums[mid]:

                    return mid
                r=mid-1
            
            elif nums[mid-1]<nums[mid] and nums[mid+1]<nums[mid]:
                return mid
            elif nums[mid-1]<nums[mid]:
                l=mid+1
            else:
                r=mid-1
            

        return -1