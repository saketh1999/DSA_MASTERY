class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res = [0] * (2*n-1)
        used = set()

        def backtracking(i):
            if i==len(res):
                return True
            
            for num in range(n,-1,-1):
                if num in used:
                    continue
                if num>1 and (i+num>=len(res) or res[i+num]):
                    continue
                
                #Prework before backtracking
                used.add(num)
                res[i] = num
                if num>1:
                    res[i+num]=num
                
                #backtracking
                j=i+1
                while j<len(res) and res[j]:
                    j+=1
                
                if backtracking(j):
                    return True

                #undoing backtracking
                used.remove(num)
                res[i] = 0
                if num>1:
                    res[i+num]=0
                
            return False
        
        backtracking(0)
        return res