class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        len_inc = 1
        len_dec = 1
        if len(nums) == 1 :
            return 1
        max_len = float('-inf')

        for i in range(1,len(nums)):
            print(nums[i-1],nums[i])
            if nums[i-1] < nums[i]:
                len_inc+=1
                print('i',len_inc)
                max_len = max(max_len,len_inc)
            else:
                len_inc = 1
        
        for i in range(1,len(nums)):
            if nums[i-1] > nums[i]:
                print('d',len_dec)
                len_dec+=1
                max_len = max(max_len,len_dec)
            else:
                len_dec = 1
        
        if max_len!=float('-inf'):
            return max_len
        else:
            return 1