class Solution {
public:
int mod =  (int)pow(10, 9) + 7;
int solver(int dies,int k, int target, vector<vector<int>>&dp)
{
     if(dies ==0 && target==0) return 1;

    if(dies==0 || target<=0)return 0;
   
    if(dp[dies][target]!=-1)
    return  dp[dies][target]%mod;

    int ways=0;
    for(int i=1;i<=k;i++)
        ways = (ways+solver(dies-1,k,target-i,dp))%mod;
    
     return dp[dies][target] =ways%mod;
}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return  solver(n,k,target,dp);
    }
};