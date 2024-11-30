class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        start_time_arr = [intervals[i][0] for i in range(len(intervals))]
        end_time_arr = [intervals[i][1] for i in range(len(intervals))]

        start_time_arr.sort()
        end_time_arr.sort()

        s_ptr,e_ptr = 0,0
        res,count=0,0
        while s_ptr<len(start_time_arr):
            if start_time_arr[s_ptr]<end_time_arr[e_ptr]:
                count+=1
                s_ptr+=1
            else:
                count-=1
                e_ptr+=1
            res=max(res,count)
        return res
