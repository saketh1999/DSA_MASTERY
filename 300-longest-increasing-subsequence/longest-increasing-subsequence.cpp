class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n,1);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]= max(dp[j]+1,dp[i]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};