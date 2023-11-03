//link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

//Iteration:
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

   
    int n= nums.size();


    vector<int> dp(n,-1);
        dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i>1)
        take = take + dp[i-2];
        int dont_take  = dp[i-1];

        dp[i]= max(take,dont_take);

    }
    return dp[n-1];

   
}

//Recursion:
#include <bits/stdc++.h> 
int find_best(vector<int> &nums,int i,vector<int>& dp)
{
    if(i==0)
    return nums[0];

    if(i<0)
    return 0;

    if(dp[i]!=-1)
    return dp[i];
     //exclude
    int not_pick = find_best(nums,i-1,dp);
     //include
    int pick = nums[i]+find_best(nums,i-2,dp);
   

   
    
    return dp[i] = max(pick,not_pick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n= nums.size();

    vector<int> dp(n,-1);

    return find_best(nums,n-1,dp);

}

