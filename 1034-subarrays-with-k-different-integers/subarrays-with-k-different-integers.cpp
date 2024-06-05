class Solution {
public:
    int subarrays(vector<int> & nums,int k)
    {
        int l=0,r=0,count=0; 
        unordered_map<int,int> mp;
        if(k<0)
        return 0;
        while(r<nums.size())
        {
            mp[nums[r]]++;

            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
   
            
                count = count + (r-l+1);

            
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c1 = subarrays(nums,k);
        int c2 = subarrays(nums,k-1);
        return c1-c2;
    }
};