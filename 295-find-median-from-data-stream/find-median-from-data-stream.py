class MedianFinder:

    def __init__(self):
        self.lHeap=[] #is a max-heap
        self.gHeap= [] #is a min-heap
    
    def addNum(self, num: int) -> None:
        heapq.heappush(self.lHeap,-1*num)

        if (self.lHeap and self.gHeap and (-1*self.lHeap[0])>self.gHeap[0]):

            val = -1 *heapq.heappop(self.lHeap)
            heapq.heappush(self.gHeap,val)

        if len(self.lHeap) > len(self.gHeap)+1:
           
            val = -1 * heapq.heappop(self.lHeap)
            print(val)
            heapq.heappush(self.gHeap,val)

        if len(self.lHeap)+1 < len(self.gHeap):
            
            val = heapq.heappop(self.gHeap)
            heapq.heappush(self.lHeap,-1*val)

    def findMedian(self) -> float:
        if len(self.lHeap) > len(self.gHeap):
            return -1*self.lHeap[0]
        
        if len(self.gHeap) > len(self.lHeap):
            return self.gHeap[0]

        else:
            return (self.gHeap[0]+-1*self.lHeap[0])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()