class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        def trav(i):
            if i==len(s):
                res.append(temp.copy())
                return
            
            for j in range(i,len(s)):
                if palindrome_check(i,j):
                    temp.append(s[i:j+1])
                    trav(j+1)
                    temp.pop()
            
            return
        
        def palindrome_check(start,end):
            while start<end:

                if s[start] == s[end]:
                    start+=1
                    end-=1
                else:
                    return False
            return True
        
        res = []
        temp = []
        trav(0)
        return res