class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre_sum=0, count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            pre_sum += nums[i];

            int x = mp[pre_sum - k] ;
            count+=x;
            
            mp[pre_sum]++;
        }
        return count;
    }
};