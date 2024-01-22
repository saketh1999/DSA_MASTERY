class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v (nums.size());
         for(int i=0;i<nums.size();i++)
         {
            v[nums[i]-1]++;

         }
         int miss , dup;
         for(int i=0;i<nums.size();i++)
         {
             if(v[i]==0)
             {
                 miss =i+1;

             }
             if(v[i]==2)
             {
                 dup = i+1;
             }

         }
         return {dup,miss};
    }
};