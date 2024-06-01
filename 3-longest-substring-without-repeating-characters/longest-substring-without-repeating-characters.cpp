class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
        return 0;
        int l =0,r=0;
        int n =s.length();
        int max_len = INT_MIN;
        unordered_map<char,int> mp;
        while(r<n)
        {
            if(mp.find(s[r])==mp.end())
            {
                max_len = max(max_len,r-l+1);
                mp[s[r]] = r;
                r++;
            }
            else{
                    l = max(mp[s[r]]+1,l);
                    mp[s[r]] = r;
                    max_len = max(max_len,r-l+1);
                    r++;
            }
        }
        return max_len;
    }
};