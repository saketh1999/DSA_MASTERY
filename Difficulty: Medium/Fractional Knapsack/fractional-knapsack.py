#User function Template for python3

class Item:
    def __init__(self,val,w):
        self.value = val
        self.weight = w
        
class Solution:    
    #Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, w,arr,n):
        
        # code here
       
        arr.sort(key=lambda x: x.value/x.weight,reverse=True)
        
        curr_w = 0
        finalvalue=0
        
        for i in range(n):
            if curr_w + arr[i].weight <= w:
                curr_w += arr[i].weight
                finalvalue += arr[i].value
            else:
                remain = w - curr_w
                finalvalue += arr[i].value / arr[i].weight * remain
                break
            
            
        
        return finalvalue


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha


class Item:

    def __init__(self, val, w):
        self.value = val
        self.weight = w


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n, w = map(int, input().strip().split())
        info = list(map(int, input().strip().split()))
        arr = [Item(0, 0) for i in range(n)]
        for i in range(n):
            arr[i].value = info[2 * i]
            arr[i].weight = info[2 * i + 1]

        ob = Solution()
        print("%.6f" % ob.fractionalknapsack(w, arr, n))

# } Driver Code Ends