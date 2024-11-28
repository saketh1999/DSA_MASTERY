class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        n = len(nums)

        #xor the first n elements
        check1 = 0
        for i in range(1,n+1):
            check1^=i
        
        #xor the elements in the array
        check2 = nums[0]
        for i in range(1,n):
            check2^=nums[i]

        #xor the result
        return check1^check2
