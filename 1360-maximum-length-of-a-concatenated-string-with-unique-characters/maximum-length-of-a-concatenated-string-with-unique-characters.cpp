class Solution {
public:
    int solver(int ind,vector<string>&arr, string  s,map<string,int>& dp)
    {
        
        unordered_set <char> rset(s.begin(),s.end());
        if(s.length()!=rset.size())
        return 0;

        if(ind >= arr.size())
        return s.length();

        if(dp.find(s)!=dp.end())return dp[s];

        int pick =0, npick = 0;
        //pick
        pick = solver(ind+1,arr,s+arr[ind],dp);
        //dont pick
        npick = solver(ind+1,arr,s,dp);
        
        int x = max(pick,npick);
        int y = s.length();
        return dp[s]=max(x,y);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        map<string,int> dp;
        return solver(0,arr,"",dp);
    }   
};