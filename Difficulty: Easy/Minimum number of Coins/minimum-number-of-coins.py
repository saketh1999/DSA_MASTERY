#User function Template for python3

class Solution:
    def minPartition(self, N):
        # code here
        coins = [1, 2, 5, 10, 20, 50, 100, 200, 500, 2000]
        sol = []
        val = N
        
        for i in range(len(coins)-1,-1,-1):
            while val >= coins[i]:
                val-=coins[i]
                sol.append(coins[i])
        return sol


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        arr = ob.minPartition(N)
        for i in range(len(arr)):
            print(arr[i],end=" ")
        print()
# } Driver Code Ends