class Solution {
public:
    int solver(int i, vector<int>&nums,vector<int>&dp)
    {
        if(i<0)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int ex = solver(i-1,nums,dp);
        int inc = nums[i]+solver(i-2,nums,dp);

        return dp[i]= max(ex,inc);

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        return max(solver(n-1,nums,dp),solver(n-2,nums,dp));
    }
};