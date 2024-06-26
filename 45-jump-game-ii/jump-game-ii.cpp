class Solution {
public:
    int jump(vector<int>& nums) {
         int l=0,r=0,farthest = 0;
         long long int jumps=0;

        while(r<nums.size()-1)
        {
            farthest =0;

            for(int i=l;i<=r;i++)
            {
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r = farthest;
            jumps+=1;
            if(farthest >= nums.size())
            return jumps;
        }
        return jumps;

        
    }
};