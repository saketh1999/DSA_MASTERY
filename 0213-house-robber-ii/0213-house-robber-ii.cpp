class Solution {
private:
int maxAmt(int n, vector<int> &nums,vector<int>&dp)
{
    if(n==0)
    return nums[0];
    if(n<0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];

    //exclude
    int left = maxAmt(n-1,nums,dp);
    
    //include
    
   int right =  nums[n]+maxAmt(n-2,nums,dp);

    return dp[n]=max(left,right);

}
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];

        vector<int> temp1,temp2;

        for(int i=0;i<n;i++)
        {
            if(i!=0)
            temp1.push_back(nums[i]);
        }
            for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            temp2.push_back(nums[i]);
        }
        vector<int> dp1(n,-1),dp2(n,-1);
        int first = maxAmt(temp1.size()-1,temp1,dp1);
        int second = maxAmt(temp2.size()-1,temp2,dp2);
       return max(first,second) ;
    }
};