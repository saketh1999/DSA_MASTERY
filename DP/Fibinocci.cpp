
#include <iostream>
#include <vector>
using namespace std;

//Fib series using recursion and Memoization
//Top down -> Top is our solution and bottom is the required answer
int fib(int n, vector<int> &dp)
{
    
    if(n<=1)
    return dp[n];
    if(dp[n]!=-1)
    return dp[n];
    return dp[n]=fib(n-1,dp) + fib(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=0,dp[1]=1;
    cout<<fib(n,dp)<<endl;
    for(int i=0;i<dp.size();i++)
    cout<<dp[i]<<" ";
}