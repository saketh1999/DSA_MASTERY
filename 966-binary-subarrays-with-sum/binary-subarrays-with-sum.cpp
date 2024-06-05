class Solution {
public:
    int subarrays(vector<int> &nums, int k)
    {
        int count =0;
        int l=0,r = 0;
        int sum=0;

        if(k<0)return 0;
       while(r<nums.size())
        {
            sum = sum + nums[r];
            
            while(sum>k)
            {
                sum-=nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int c1 = subarrays(nums,goal) ;
    int c2 = subarrays(nums,goal-1);
    return c1-c2;
    }
};