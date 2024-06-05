class Solution {
public:
    void oddEvenCheck(vector<int> & nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
    }
    int countSubarrays(vector<int>& nums, int k)
    {
        if(k<0)
        return 0;

        int l=0,r=0,sum=0,count=0;

        while(r<nums.size())
        {
            sum+=nums[r];

            while(sum>k)
            {
                sum-=nums[l];
                l++;
            }
            if(sum<=k)
            count += r-l+1; // we are counting all subarrays till r,
            //which satisy the condition of sum <= k

            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        oddEvenCheck(nums);
        int c1 = countSubarrays(nums,k);
        int c2 = countSubarrays(nums,k-1);

        return c1 - c2;
        
    }
};