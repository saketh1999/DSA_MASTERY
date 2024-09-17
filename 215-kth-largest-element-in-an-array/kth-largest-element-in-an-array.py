class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        length = len(nums) - k

        while len(nums) > k:
            heapq.heappop(nums)
        
        return nums[0]
