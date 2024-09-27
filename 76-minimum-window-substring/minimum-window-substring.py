class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l,r = 0,0 
        minLen = math.inf
        count = 0
        start_ind = -1
        
        mydict = {}

        for i in range(len(t)):
            if t[i] in mydict:
                mydict[t[i]] += 1
            else:
                mydict[t[i]] = 1
        
        while r < len(s):

            if s[r] in mydict:
                if mydict[s[r]] > 0:
                    count +=1
                mydict[s[r]] -= 1
                
            else:
                mydict[s[r]] = -1
            
            while count == len(t):

                if r-l+1 < minLen:
                    minLen = r-l+1
                    start_ind = l

                mydict[s[l]] +=1

                if mydict[s[l]] > 0:
                    count -=1
                
                l+=1
            r+=1

        if start_ind == -1 :
            return ""
        else :
            return s[start_ind:start_ind+minLen]
        



