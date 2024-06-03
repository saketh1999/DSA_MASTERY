class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int max_freq=0;
        int l=0,r=0;
        int max_len=0;
        while(r<s.length())
        {
            mp[s[r]]++;
            max_freq= max(max_freq,mp[s[r]]);

            if((r-l+1)-max_freq > k)
            {
                mp[s[l]]--;
                l++;
            }
            else{
                max_len = max(max_len,r-l+1);
            }
            r++;
        }
        return max_len;
    }
};