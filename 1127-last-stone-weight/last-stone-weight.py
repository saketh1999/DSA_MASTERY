class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        myhash = [-s for s in stones]

        heapq.heapify(myhash)

        while len(myhash)>1:
            first = heapq.heappop(myhash)
            second =heapq.heappop(myhash)

            if first != second:
                heapq.heappush(myhash,first-second)
            

        if len(myhash) == 0:
            return 0
        return abs(myhash[0])
                