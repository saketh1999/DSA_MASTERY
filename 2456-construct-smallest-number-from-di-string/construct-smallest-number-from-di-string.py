class Solution:
    def smallestNumber(self, pattern: str) -> str:
        stack = []
        res=[]
        for i in range(len(pattern)+1):
            stack.append(i+1)

            while stack and (i==len(pattern) or pattern[i]=='I' ):
                res.append(str(stack.pop(-1)))
            
        return "".join(res)
