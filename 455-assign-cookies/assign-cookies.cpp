class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
        return 0;
        int greedIdx = g.size()-1;
        int cookiesIdx = s.size()-1;

        //Sort the cookies and greed factors
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int children=0;
        while(greedIdx>=0 && cookiesIdx>=0)
        {
            if(s[cookiesIdx]>=g[greedIdx])
            {
                children++;
                cookiesIdx--;
                greedIdx--;
            }
            else
            {
                //Since the cookies at other index can be used to satisfy the 
                //greed of other children
                greedIdx--;
            }
        }
        return children;

        
    }
};