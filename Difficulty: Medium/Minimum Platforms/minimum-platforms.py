#User function Template for python3

class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,arr,dep):
        # code here
        arr.sort()
        dep.sort()
        
        maxCounter = 0
        counter = 0 
        
        i,j=0,0
        
        while i<len(arr) and j<len(dep):
            if arr[i] <= dep[j]:
                i+=1
                counter+=1
                maxCounter = max(maxCounter,counter)
            else : 
                j+=1
                counter-=1
        
        return maxCounter
            
            

#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.minimumPlatform(arrival, departure))

# } Driver Code Ends