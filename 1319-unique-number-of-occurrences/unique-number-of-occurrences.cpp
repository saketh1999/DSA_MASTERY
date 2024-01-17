class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x : arr)
        {
            mp[x]++;
        }
        unordered_set<int> s;
        for(auto y: mp)
        {
            s.insert(y.second);
        }
        if(mp.size()==s.size())
        return true;
        else return false;
    }
};