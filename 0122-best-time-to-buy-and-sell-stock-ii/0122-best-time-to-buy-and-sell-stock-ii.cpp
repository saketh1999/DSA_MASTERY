class Solution {
private:
private: 
int sellOrBuy(int ind,int buy, vector<int>&price, vector<vector<int>> &dp)
{
    if(ind == price.size()) //end of all
    return 0;


    if(dp[ind][buy]!=-1)
    return dp[ind][buy];

    int profit1 = INT_MIN,profit2=INT_MIN;
    if(buy)
    {
        //if you buy the stock in ind day
        profit1 = -price[ind]+ sellOrBuy(ind+1,0,price,dp);

        //if you decide not to buy
        profit2 = sellOrBuy(ind+1,1,price,dp);

        profit1=max(profit1,profit2);
        
    }
    else //you bought on the ind-1 day so now you can sell or not
    {
        //if you sell
        profit1 = price[ind] + sellOrBuy(ind+1,1,price,dp);

        //if you decide not to sell
        profit2 = sellOrBuy(ind+1,0,price,dp);
         
        profit1=max(profit1,profit2);
    }
    return dp[ind][buy] = profit1;
}
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

         return sellOrBuy(0,1,prices,dp);

        
    }
};