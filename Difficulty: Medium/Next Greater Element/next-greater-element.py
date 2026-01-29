class Solution:
    def nextLargerElement(self, arr):
        # code here
        res = [0]*(len(arr))
        stack = []
       
        
        
        for i in range(len(arr)-1,-1,-1):
            
            
            while stack and stack[-1]<=arr[i]:
               stack.pop(-1)
            
            if not stack:
                res[i]=-1
            else:
                res[i]= stack[-1]

            stack.append(arr[i])
      
        return res