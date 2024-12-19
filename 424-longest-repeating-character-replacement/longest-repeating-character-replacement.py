class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        my_dict={}
        max_freq=0
        l,r=0,0
        max_len=0
        while r<len(s):
            if s[r] in my_dict:
                my_dict[s[r]]+=1
            else:
                my_dict[s[r]]=1
            
            max_freq = max(max_freq,my_dict[s[r]])

            if (r-l+1)-max_freq<=k:
                max_len = max(max_len,r-l+1)
            
            else:
                my_dict[s[l]]-=1
                l+=1

            r+=1

        return max_len
