//Link: https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=DISCUSS


//Recursive Solution:
#include <bits/stdc++.h> 
int minEnergy(int n, vector<int> &h, vector<int> &minE)
{
    if(n==0)
    return 0;

    if(minE[n]!=-1)
    return minE[n];

    int left,right=INT_MAX;
    left = minEnergy(n-1,h,minE)+ abs(h[n]-h[n-1]);
    if(n>1)
    right = minEnergy(n-2,h,minE) + abs(h[n]-h[n-2]);

    return minE[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> minE (n+1,-1);
  
    return minEnergy(n-1,heights,minE);
    // Write your code here.
}


//Bottom Up

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);

    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        int first = dp[i-1] + abs(heights[i-1] - heights[i]);
        int second=INT_MAX;
        if(i>1)
        second = dp[i-2] + abs(heights[i-2] - heights[i]);

        dp[i]=min(first,second);

        

    }
        return dp[n-1];
    // Write your code here.
}