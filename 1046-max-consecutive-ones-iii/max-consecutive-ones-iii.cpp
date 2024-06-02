class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,max_len=0;
        int len=0,zero=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==0)
            {
                zero++;
            }
            if(zero>k)
            {
                if(nums[l]==0)
                zero--;

                l++;
               
            }
            else if(zero<=k)
            {
                len = r-l+1;
                max_len = max(len,max_len);
                
            }
            
        }
        return max_len;
    }
};