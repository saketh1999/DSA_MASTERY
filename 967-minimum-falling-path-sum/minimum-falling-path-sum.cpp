class Solution {
public:
    int solver(int i,int j,vector<vector<int>>&mat , vector<vector<int>>&dp)
    {
        int m = mat.size();
        int n = mat[0].size();
        
       if(dp[i][j]!=INT_MAX)
       return dp[i][j];
       if(i==m-1)
       return mat[i][j];

        int left=INT_MAX,down,right=INT_MAX;
       if(j>0)
        left = solver(i+1,j-1,mat,dp);
       if(j<n-1)
        right = solver(i+1,j+1,mat,dp);
      
        down = solver(i+1,j,mat,dp);

        dp[i][j] = min(down,min(left,right)) + mat[i][j];

        return dp[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 || n == 1) return matrix[0][0];
        vector<vector<int>> dp (m,vector<int>(n,INT_MAX));
        int mini = INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini = min(mini,solver(0,i,matrix,dp));
        }
        return mini;
    }
};