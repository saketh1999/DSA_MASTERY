class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        #Backtracking solution
        def calculate(i,curr):
            
            if curr==n:
                return True
                
            if curr>n or 3**i>n:
                return False
            
            #pick the current power of 3
            if calculate(i+1,curr+3**i):
                return True
            
            #dont pick current power of 3
            return calculate(i+1,curr)

        return calculate(0,0)