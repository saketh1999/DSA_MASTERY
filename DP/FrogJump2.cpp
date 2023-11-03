int minEnergy(int n, int k , vector<int> & h, vector<int>&dp)
{
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];

    int small=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {int x = minEnergy(n-i,k,h,dp) + abs(h[n]-h[n-i]);
        small=min(x,small);}
    }

    return dp[n]=small;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n+1,-1);
    dp[0]=0;
    return minEnergy(n-1,k,height,dp);

}