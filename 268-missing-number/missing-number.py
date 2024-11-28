class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        n = len(nums)
        check1 = 0
        for i in range(1,n+1):
            check1^=i
        check2 = nums[0]
        for i in range(1,n):
            check2^=nums[i]
        print
        return check1^check2
