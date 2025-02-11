class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res=[]
        myStr = []

        def generator(openB,closeB):
            if openB == 0 and closeB==0:
                copy = "".join(myStr)
                res.append(copy)
            
            if openB>0:
                myStr.append('(')
                generator(openB-1,closeB)
                myStr.pop()

            if closeB>openB:
                myStr.append(')')
                generator(openB,closeB-1)
                myStr.pop()
        generator(n,n)
        return res

