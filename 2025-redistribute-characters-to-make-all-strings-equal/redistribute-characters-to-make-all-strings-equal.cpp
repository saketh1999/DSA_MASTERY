class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> mp;
        for(auto x : words)
        {
            for(auto y : x)
            mp[y]++;
        }
        for(auto y : mp)
        {
            if (y.second%n!=0)
            return false;

        }
        return true;
    }
};