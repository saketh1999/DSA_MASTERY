//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int l=0,r=0,k=2;
        int max_len=0,len=0;
        unordered_map<int,int> mp;
        while(r<N)
        {
            mp[fruits[r]]++;
            
            if(mp.size()>k)
            {
                mp[fruits[l]]--;
                
                if(mp[fruits[l]]==0)
                mp.erase(fruits[l]);
                
                l++;
               
            }
             else if(mp.size()<=k)
            {
                len = r-l+1;
                max_len = max(max_len,len);
                
            }
            r++;
             
        }
        return max_len;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends