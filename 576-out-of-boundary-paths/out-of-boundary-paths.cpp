class Solution {
    int mod = 1e9+7;
public:
    int solver(int i,int j, int maxMoves, int m, int n,vector<vector<vector<long long>>>& dp)
    {
        
        
        if(i>=m || i<0 || j>=n || j <0)
        return 1;
        if(maxMoves <=0)
        return 0;

        if(dp[i][j][maxMoves]!=-1)
        return dp[i][j][maxMoves];
        long long up = solver(i-1,j,maxMoves-1,m,n,dp);
        long long down = solver(i+1,j,maxMoves-1,m,n,dp);

        long long left = solver(i,j-1,maxMoves-1,m,n,dp);
        long long right = solver(i,j+1,maxMoves-1,m,n,dp);

        return dp[i][j][maxMoves]= (up+down+left+right)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp (m+1,vector<vector<long long>>(n+1,vector<long long>(maxMove+1,-1)));
        return solver(startRow,startColumn,maxMove,m,n,dp);
    }
};