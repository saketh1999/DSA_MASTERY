class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        myStr = []
        openB,closeB = 0,0
        

        def my_counter(myStr,openB,closeB,res,n):
            if openB == n and closeB == n:
                res.append("".join(myStr))
                return
            
            if openB < n:
                myStr.append("(")
                my_counter(myStr,openB+1,closeB,res,n)
                myStr.pop()

            if closeB < openB:
                myStr.append(")")
                my_counter(myStr,openB,closeB+1,res,n)
                myStr.pop()

        my_counter(myStr,0,0,res,n)
        return res
            



