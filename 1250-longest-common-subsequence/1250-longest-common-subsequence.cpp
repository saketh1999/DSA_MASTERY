class Solution {
private:
    int LCS(int ind1,int ind2,string text1, string text2,vector<vector<int>> & dp)
    {
        if(ind1 < 0 || ind2 < 0)
        return 0;

        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2])
        {
            return dp[ind1][ind2] = 1 + LCS(ind1-1,ind2-1,text1,text2,dp);
        }
        else
        {
            return dp[ind1][ind2] = max(LCS(ind1-1,ind2,text1,text2,dp),LCS(ind1,ind2-1,text1,text2,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                
                    dp[i][j]+=1+dp[i-1][j-1];
                }
                else {
                 
                  
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                   
                }
            }
        }
        return dp[m][n];
   
    }
};