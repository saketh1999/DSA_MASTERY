class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        #brute for would be find all subarrays and then find minimums in each and add them

        #Optimised solution

        def nextSmallestElement(arr):
            n = len(arr)
            nse = [0]*n
            stack = []

            for i in range(n-1,-1,-1):
                if not stack:
                    nse[i]=n
                
                elif stack and arr[stack[-1]] < arr[i]:
                    nse[i] = stack[-1]
                
                elif stack and arr[stack[-1]] >= arr[i]:
                    while stack and arr[stack[-1]] >= arr[i]:
                        stack.pop()
                    
                    if not stack:
                        nse[i]=n
                    else:
                        nse[i] = stack[-1]
                
                stack.append(i)
        
            return nse

        def prevSmallestElement(arr):
            n = len(arr)
            pse = [0]*n
            stack = []

            for i in range(0,n):
                if not stack:
                    pse[i]=-1
                
                elif stack and arr[stack[-1]] <= arr[i]:
                    pse[i] = stack[-1]
                
                elif stack and arr[stack[-1]] > arr[i]:
                    while stack and arr[stack[-1]] > arr[i]:
                        stack.pop()
                    
                    if not stack:
                        pse[i]=-1
                    else:
                        pse[i] = stack[-1]
                
                stack.append(i)
        
            return pse
        pse= prevSmallestElement(arr)
        nse= nextSmallestElement(arr)

        print(nse,pse)

        sum = 0
        for i in range(len(arr)):
            left = i-pse[i]
            right = nse[i]-i
            sum = (sum+ (right*left*arr[i]))%(10**9+7)
        return sum