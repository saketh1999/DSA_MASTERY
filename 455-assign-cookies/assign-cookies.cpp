class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
        return 0;
        int greedIdx = g.size()-1;
        int cookiesIdx = s.size()-1;
        int children=0;

        //Sort the cookies and greed factors
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

            while(cookiesIdx>=0 && greedIdx>=0)
            {
                if(g[greedIdx]<=s[cookiesIdx])
                {
                    children++;
                    greedIdx--;
                    cookiesIdx--;
                }
                else{
                    greedIdx--;
                }
            }
        
        return children;

        
    }
};