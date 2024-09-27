class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = {}
        prefixSum[0] = 1
        sum = 0
        res = 0
        for i in range(len(nums)):

            sum += nums[i]

            diff = sum - k

            if diff in prefixSum:
                res += prefixSum[diff]
            
            if sum in prefixSum:
                prefixSum[sum] += 1
            else:
                prefixSum[sum] = 1
        
        return res