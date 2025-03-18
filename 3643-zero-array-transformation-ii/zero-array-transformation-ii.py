class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        diff_arr = [0]*(len(nums)+1)

        pos = 0
        sum = 0

        for i in range(len(nums)):
            while sum+diff_arr[i] < nums[i]:

                if pos == len(queries):
                    return -1
                
                start = queries[pos][0]
                end = queries[pos][1]
                val = queries[pos][2]

                pos+=1

                if end<i:
                    continue

                diff_arr[max(i,start)]+=val
                diff_arr[end+1]-=val
            
            sum+=diff_arr[i]
        
        return pos
