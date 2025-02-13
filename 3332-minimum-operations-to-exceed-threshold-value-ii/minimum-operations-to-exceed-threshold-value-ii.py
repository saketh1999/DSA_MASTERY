class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        #we need priority queue
        li = []
        count_gk = 0
        for x in nums:
            if x >= k:
                count_gk+=1
            li.append(x)

        heapq.heapify(li)

        operation_count = 0
        while len(li)>=2 and count_gk<len(li):
            operation_count+=1
            x = heapq.heappop(li)
            y = heapq.heappop(li)
     
            res = min(x,y)*2 + max(x,y)

            if res >= k:
                count_gk+=1

            heapq.heappush(li,res)

            if count_gk>=len(li):
                return operation_count
           

        return operation_count




