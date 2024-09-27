class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        myHash = {}
        l,r = 0,0
        maxLen,maxFreq = 0,0
        while r < len(s):
            if s[r] in myHash:
                myHash[s[r]]+=1
            else :
                myHash[s[r]] = 1
            
            maxFreq = max(maxFreq,myHash[s[r]])

            if (r-l+1) - maxFreq <= k:
                maxLen = max(maxLen,r-l+1)
            else:
                myHash[s[l]] -= 1
                l+=1
            r+=1

        return maxLen

            
            