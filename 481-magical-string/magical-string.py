class Solution:
    def magicalString(self, n: int) -> int:
        s = [1,2,2]

        for i in range(2,n):
            s+= [3-int(s[-1])] * s[i]
            
        return s[:n].count(1)
        