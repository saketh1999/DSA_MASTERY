class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win,loss;
        for(int i=0;i<matches.size();i++)
        {
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }
        vector<int> w,l;
        for(auto x : loss)
        {
            if(x.second==1)
            {
                l.push_back(x.first);
            }
        }
        for(auto y : win)
        {
            if(loss.find(y.first)==loss.end())
            {
                w.push_back(y.first);
            }
        }
        return {w,l};
    }
};