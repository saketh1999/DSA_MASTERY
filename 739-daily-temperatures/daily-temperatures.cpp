class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Monotonic Stack solution
        int n = temperatures.size();
        stack<pair<int,int>> s;
        vector<int> sol(n,0);

        //s.push({temperatures[n-1],n-1});
        for(int i=n-1;i>=0;i--)

        {
            while(!s.empty() && s.top().first <= temperatures[i])s.pop();

           

            if(!s.empty())
            {
                sol[i] = s.top().second - i;
               
            }
             s.push({temperatures[i],i});
          
        }
        return sol;
    }
};