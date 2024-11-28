class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        def helper(x,n):
            if x==0:
                return 0
            if n==0:
                return 1
            
            res = helper(x,n//2)
            res*=res
            if n&1 == True:
                res*=x
            return res

        res = helper(x,abs(n))#just finding the normal x^n    
        if n<0:
            return 1/res
        return res