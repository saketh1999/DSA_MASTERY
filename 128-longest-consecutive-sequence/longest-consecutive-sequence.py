class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        my_set = set(nums)
        max_len=0
        curr_len = 1
        for x in my_set:
            if x-1 not in my_set:
                curr_len=1
                curr_num = x

                while curr_num+1 in my_set:
                    curr_len+=1
                    curr_num+=1

                max_len = max(max_len,curr_len)
        return max_len

