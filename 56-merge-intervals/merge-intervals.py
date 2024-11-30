class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        intervals.sort(key=lambda intervals: intervals[0]) #sorting based on the first value in each interval

        #merge them now
        res = [intervals[0]]

        for i in range(1,len(intervals)):
            prev = res[-1]
            curr = intervals[i]

            if curr[0] <= prev[1]:
                prev[1] = max(curr[1],prev[1])
            else:
                res.append(curr)
        
        return res
