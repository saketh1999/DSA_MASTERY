class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            for(int j=1;j<s.length();j++)
            {
                if(s[i]==s[j])
                {
                    ans=max(ans,j-i);
                }

            }
        }
        return ans-1;
    }
};