class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if len(intervals)==0:
            return True
        intervals.sort(key=lambda x:x[0])

        prev_end = intervals[0][1]
        for i in range(1,len(intervals)):
            if prev_end>intervals[i][0]:
                return False
            prev_end=intervals[i][1]

        return True