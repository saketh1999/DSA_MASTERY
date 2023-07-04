//Leetcode: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/


////////////////////////////////////////////////
/*
                SOLUTION 1
*/
////////////////////////////////////////////////
//TC -> O(N)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        for(int i=0;i<letters.size();i++)
        {
            if(target<letters[i])
            {
                ans=letters[i];
                return ans;
            }
        }
     
        return letters[0];
      
    }
};

////////////////////////////////////////////////
/*
                SOLUTION 2
*/
////////////////////////////////////////////////
//Binary Search solution
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //Binary Seach Solution
        char ans;
        int start=0,end=letters.size()-1;
        int mid=0;
        if(letters[end]<=target)return letters[0];
        while(start<=end)
        {
             mid= start+( end-start)/2;
            if(letters[mid]>target)
            {
                ans=letters[mid];
                 end=mid-1;
            }
            else
            {
               start=mid+1;
            }
        }
        return ans;

    }
};