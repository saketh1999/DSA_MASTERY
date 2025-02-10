class Solution:
    def clearDigits(self, s: str) -> str:
        #step 1 : count the number of digits and the last_indx of a digit
        res = []
        last_indx=-1
        n = len(s)
        for i in range(len(s)):
            if s[i].isalpha():
                res.append(s[i])
            else:
                res.pop()
        
        return "".join(res)
            

