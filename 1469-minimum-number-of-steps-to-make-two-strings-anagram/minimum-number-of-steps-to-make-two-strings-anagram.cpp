class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sc(26,0);
        vector<int> tc(26,0);

        for(int i=0;i<s.length();i++)
        {
            sc[int(s[i])-97]++;
        }
          for(int i=0;i<t.length();i++)
        {
            tc[int(t[i])-97]++;
        }
        int ans=0;

        for(int i=0;i<26;i++)
        {
            ans += abs(sc[i]-tc[i]);
        }
        return ans/2;
    }
};