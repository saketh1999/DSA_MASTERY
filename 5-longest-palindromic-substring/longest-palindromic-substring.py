class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        res = ""
        for i in range(n):
            
            #odd length palindrome
            left,right = i,i
            while left>=0 and right<n and s[right]==s[left]:
                if right-left+1 > len(res):
                    res = s[left:right+1]
                left-=1
                right+=1
            
            #even length palindrom
            left,right = i,i+1
            while left>=0 and right<=n-1 and s[right]==s[left]:
                if right-left+1 > len(res):
                    res = s[left:right+1]
                left-=1
                right+=1
            

        return res
