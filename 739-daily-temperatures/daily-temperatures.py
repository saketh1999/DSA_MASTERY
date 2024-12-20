class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        sol = [0]*len(temperatures)
        for i in range(len(temperatures)-1,-1,-1):
            while len(stack)>0 and stack[-1][0]<=temperatures[i]:
                stack.pop()
            
            if len(stack):
                sol[i] = stack[-1][1]-i
            
            stack.append([temperatures[i],i])
        return sol