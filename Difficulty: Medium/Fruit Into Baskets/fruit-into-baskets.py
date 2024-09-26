#User function Template for python3

class Solution:
    def totalFruits(self,arr):
        # Code here
        myMap = {}
        maxLen = -1
        left,right = 0,0
        
        while  right<len(arr):
            if arr[right] in myMap:
                myMap[arr[right]] += 1
            else:
                myMap[arr[right]] = 1
                
            
            if len(myMap)>2:
                
                myMap[arr[left]] -= 1
                if myMap[arr[left]] == 0:
                    del myMap[arr[left]]
                left += 1
            else:
                maxLen = max(maxLen,right-left+1)
                
            right+=1      
           
        return maxLen

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        # N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.totalFruits(arr)
        print(res)

# } Driver Code Ends