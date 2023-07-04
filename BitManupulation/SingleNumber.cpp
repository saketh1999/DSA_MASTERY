//LeetCode: https://leetcode.com/problems/single-number/

////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////

//TC -> O(N) but Space complexity is O(N), we need to optimize it further
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        res^=nums[i];

        return res;
    }
};

//Using Bit manupulation