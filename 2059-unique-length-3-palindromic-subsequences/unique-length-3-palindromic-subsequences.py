class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        my_set = set(s)
        ans = 0
        for x in my_set:
            first,last = s.index(x),s.rindex(x)

            between = set()
            for i in range(first+1,last):
                between.add(s[i])
            
            ans+=len(between)
        
        return ans