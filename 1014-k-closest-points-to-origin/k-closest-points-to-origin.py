class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        dist = []
        sol = []


        for val in points:
            print(val)
            x = val[0]
            y = val[1]

            dis = math.sqrt( x*x + y*y )
            dist.append([-dis,x,y])

        
        heapq.heapify(dist)


        while len(dist) > k:
            heapq.heappop(dist)
        

        for val in dist:    
            _,x,y = val
            sol.append([x,y])


        return sol

