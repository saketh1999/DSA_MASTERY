class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        count = Counter(tasks)

        myheap = [-val for val in count.values()]

        myq = deque()

        heapq.heapify(myheap)
        time=0
        while myheap or myq:
            time+=1

            if not myheap:

                time = myq[0][1]
            else:
                cnt = -heapq.heappop(myheap) - 1
                if cnt:
                    myq.append([cnt,time+n])
            
            if myq and myq[0][1]==time:
                heapq.heappush(myheap,-myq.popleft()[0])
            
        return time
