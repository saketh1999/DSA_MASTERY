class Solution:
    def minCut(self, s: str) -> int:
        self.dp = [[-1 for i in range(len(s))] for i in range(len(s))]
        self.pal = [[-1 for i in range(len(s))] for i in range(len(s))]
        
        def trav(start,end,min_cut):
            if start==end or palindrome_check(start,end):
                return 0 # reason: if it is a palindrom we need not cut it - or it if is an empty string
            
            if self.dp [start][end]!=-1:
                return self.dp[start][end]

            for j in range(start,end+1): #this for function check for the current partion and if it a palindrome
            #only it will check for the next partion if it is a substring
                if palindrome_check(start,j):
                    min_cut = min(min_cut,1+trav(j+1,end,min_cut))
                    self.dp[start][end] = min_cut
                
            
            return self.dp[start][end]
        
        def palindrome_check(start,end):
            
            if start>=end:
                return True

            if self.pal[start][end]!=-1:
                return self.pal[start][end]

            self.pal[start][end] = s[start]==s[end] and palindrome_check(start+1,end-1)
            return self.pal[start][end]
       
        return trav(0,len(s)-1,len(s)-1)
