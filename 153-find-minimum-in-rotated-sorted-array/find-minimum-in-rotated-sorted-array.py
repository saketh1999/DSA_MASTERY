class Solution:
    def findMin(self, nums: List[int]) -> int:
        low,high=0,len(nums)-1
        smallest = math.inf
        while(low<=high):
            mid = (low+high)//2


            if nums[mid] >= nums[low]:
                if nums[low] < smallest:
                    smallest = nums[low]
                low = mid+1

            else :
                if smallest > nums[mid]:
                    smallest= nums[mid]
                high = mid -1

        return smallest
