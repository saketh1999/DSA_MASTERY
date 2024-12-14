class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        l,r=0,0
        char_dict={}
        max_len = 0
        while r<len(s):
            if s[r] not in char_dict:
                char_dict[s[r]]=1
            else:
                char_dict[s[r]]+=1

            while len(char_dict)>k:
                char_dict[s[l]]-=1

                if char_dict[s[l]]==0:
                    char_dict.pop(s[l])
                l+=1
            max_len = max(max_len,r-l+1)
            r+=1
        
        return max_len
            