class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        //Bottom Up Appoach

        for(int i = n-1; i>=0; i--)
        {
            int maxi=INT_MIN,ans=0;
        for(int j=i; j<min(n,i+k);j++) // running j till min(n or ind+k)
        {
            maxi=max(arr[j],maxi);
            ans = max(ans, (j-i+1)*maxi + dp[j+1]); // since we are stating from
            //ind, we need to do j+1 call each time .
            //Finall call will be to j+ind-1
        }
        dp[i] = ans;
        }
        return dp[0];
    }
};