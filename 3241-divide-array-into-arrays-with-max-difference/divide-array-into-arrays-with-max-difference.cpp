class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
       
        vector<vector<int>> sol;
        int n = nums.size();
       
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=3)
        {
            vector<int> res;

            if(i+2<=n-1 && (nums[i+2]-nums[i] <= k))
            {
               
                int j = i;
              while(j<=i+2)
              {
                  res.push_back(nums[j]);
                  j++;
              }   
            }
            if(res.size()==0)
            return {};
            sol.push_back(res);
        }
        return sol;
    }
};