class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        myStr = []
        openB,closeB=0,0
        def generator(openB,closeB):
            if openB == n and closeB==n:
                copy = "".join(myStr)
                res.append(copy)
            
            if openB<n:
                myStr.append('(')
                generator(openB+1,closeB)
                myStr.pop()

            if closeB<openB:
                myStr.append(')')
                generator(openB,closeB+1)
                myStr.pop()
        generator(0,0)
        return res

