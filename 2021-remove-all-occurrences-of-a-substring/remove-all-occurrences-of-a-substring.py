class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n = len(part)
        lps_arr = [0]*n
        
        def LPS(patt,lps):
            len = 0
            i=1
            while i<n:
                if patt[i] == patt[len]:
                    len+=1
                    lps[i]=len
                    i+=1
                    

                else:
                    if len!=0:
                        len = lps[len-1]
                    else:
                        lps[i]=0
                        i+=1

            return lps

        lps = LPS(part,lps_arr)
        print(lps)

        j,i=0,0
        m = len(s)
        while i<m:
            if s[i] == part[j]:
                i+=1
                j+=1

                if j==n:
                    s = s[:i-n]+s[i:]
                    m=len(s)
                    i=max(0,i-2*n)
                    j=0
            
            else:
                if j!=0:
                    j=lps[j-1]
                
                else:
                    i+=1
        return s