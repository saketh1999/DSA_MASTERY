class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long  mod = 1e9+7;
        int n  = arr.size();
        
        vector<long long> left(n,0),right(n,0);

        stack<pair<int,int>> sRight,sLeft;

        for(int i =0;i<arr.size();i++)
        {
            int count = 1;
            while(!sLeft.empty() && sLeft.top().first>=arr[i])
            {
                count+=sLeft.top().second ; //Adding the count of the first element also
                sLeft.pop();
            }
            sLeft.push({arr[i],count});
            left[i] = count;
        }
        
        for(int i =n-1;i>=0;i--)
        {
            int count = 1;
            while(!sRight.empty() && sRight.top().first>arr[i])
            {
                count+=sRight.top().second ; //Adding the count of the first element also
                sRight.pop();
            }
            sRight.push({arr[i],count});
            right[i] = count;
        }
        
        long long int res = 0 ;
        for(int i=0;i<arr.size();i++)
        {
            
            res += (arr[i]*left[i]*right[i]);
            res = res%mod;
            
        }
        return res;
    }
};