class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //O(1) space complexity
        int n = temperatures.size();
        vector<int> sol (n,0);
        int hottest = -1;
        for(int i = n-1; i >=0 ; i-- )
        {
            if(temperatures[i]>= hottest)
            {
                hottest = temperatures[i];
                continue;
            }
        
            int day=1;
            
            
            while(temperatures[i+day] <= temperatures[i])
            {
                day+=sol[i+day];
            }
            sol[i]=day;
            
        }
        return sol;
        

    }
};