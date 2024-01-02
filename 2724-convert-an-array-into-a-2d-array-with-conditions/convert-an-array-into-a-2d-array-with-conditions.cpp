class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            
            mp[nums[i]]++;
            maxi = max(maxi,mp[nums[i]]);

        }

        vector<vector<int>> ans(maxi);
        int i=0;
        for(auto x: mp)
        {
            while(x.second)
            {
                ans[i].push_back(x.first);
                i++;
                x.second--;
            }
            i=0;
            
        }
        return ans;
        
    }
};