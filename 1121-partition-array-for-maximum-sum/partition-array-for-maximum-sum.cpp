class Solution {
public:
    int solver(int ind, vector<int>& arr,vector<int> & dp,int k)
    {
        int n =arr.size();
        if(ind>=n)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int maxi=INT_MIN,ans=0;
        for(int j=ind; j<min(n,ind+k);j++)
        {
            maxi=max(arr[j],maxi);
            ans = max(ans, (j-ind+1)*maxi + solver(j+1,arr,dp,k));
        }
       return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return solver(0,arr,dp,k);
    }
};