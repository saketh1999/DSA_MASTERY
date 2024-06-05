class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;

        int l=0,r=0,count=0;
        int st_indx=0,min_len=INT_MAX;

        for(int i=0;i<t.length();i++)
        {
            mp[t[i]]++;
        }

        while(r<s.length())
        {
        
            if(  mp[s[r]]>0) 
            {
                count++;
                
            }
            mp[s[r]]--;
    

            while(count == t.length())
            {
                if(r-l+1<min_len)
                {
                      st_indx = l;
                      min_len = r-l+1;
                }
              

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                count--;

                l++;
            }

            r++;





        }

        return min_len == INT_MAX ? "" : s.substr(st_indx,min_len);
    }
};