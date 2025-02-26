class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        prefix_sum_min = 0
        prefix_sum_max = 0
        curr_sum =0
        res = 0
        for x in nums:
            curr_sum+=x
            res = max(res,abs(curr_sum-prefix_sum_min),abs(curr_sum-prefix_sum_max))
            prefix_sum_max = max(prefix_sum_max,curr_sum)
            prefix_sum_min = min(prefix_sum_min,curr_sum)
        return res