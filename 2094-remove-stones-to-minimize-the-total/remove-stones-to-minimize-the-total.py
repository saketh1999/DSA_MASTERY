class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        my_heap = []
        for i in range(len(piles)):
            my_heap.append(-1*piles[i])

        heapq.heapify(my_heap)

        while k:
            val = heapq.heappop(my_heap)
            heapq.heappush(my_heap,val//2)
            k-=1
        sum=0
        for i in range(len(my_heap)):
            sum+=-1*my_heap[i]
        return sum