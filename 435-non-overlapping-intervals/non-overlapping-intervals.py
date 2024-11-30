class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:x[0])

        res = 0
        prev_end = intervals[0][1]

        for i in range(1,len(intervals)):
            curr_start = intervals[i][0]
            if curr_start>= prev_end:
                prev_end=intervals[i][1]
            else:
                res+=1
                prev_end = min(prev_end,intervals[i][1])
        return res