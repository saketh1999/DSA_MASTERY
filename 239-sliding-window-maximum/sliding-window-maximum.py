class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        #queue
        q = deque()
        res =[]

        for i in range(len(nums)):
            if q and q[0] <= i-k:
                q.popleft() #pop from the front
            
            while q and nums[q[-1]] <= nums[i]:
                q.pop() #pop from the back
            q.append(i)

            if i+1>=k:
                res.append(nums[q[0]])
        return res