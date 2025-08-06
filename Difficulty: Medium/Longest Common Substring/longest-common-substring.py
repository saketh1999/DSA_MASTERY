#User function Template for python3

class Solution:
        
    def longestCommonSubstr(self, s1, s2):
        row = len(s1)
        col = len(s2)
        dp = [[0 for i in range(col+1)]for j in range(row+1)]
        ans = 0
        
        # def solver(i,j):
        #     if i<0 or j<0:
        #         return 0
            
        #     if dp[i][j]!=-1:
        #         return dp[i][j]
                
            
        #     #same 
        #     if s1[i-1] == s2[j-1]:
        #         print("hi")
        #         dp[i][j]= 1+solver(i-1,j-1)
        #         print(dp[i][j])
        #         self.ans = max(dp[i][j],ans)
        #     #
        #     else:
        #         dp[i][j] = max(solver(i-1,j),solver(i,j-1))
            
        #     return dp[i][j]
        
        def solver_td(ans):
            for i in range(row):
                dp[i][0] = 0
            for i in range(col):
                dp[0][i] = 0
            
            for i in range(1,row+1):
                for j in range(1,col+1):
                    if s1[i-1] == s2[j-1]:
                        dp[i][j] = 1+dp[i-1][j-1]
                        ans = max(ans,dp[i][j])
                    else:
                        dp[i][j]=0
            
            return ans
        
        return solver_td(ans)
                    
            
        
        
  