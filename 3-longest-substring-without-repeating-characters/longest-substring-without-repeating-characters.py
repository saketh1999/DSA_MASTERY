class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        my_dict = {}

        l,r=0,0
        n=len(s)
        max_len = 0

        while(r<n):
         if s[r] in my_dict:

            l = max(my_dict[s[r]]+1,l)
            my_dict[s[r]]=r
            max_len = max(max_len,r-l+1)
            
         else:

            max_len = max(max_len,r-l+1)
            my_dict[s[r]]=r
         r+=1
        return max_len
        

