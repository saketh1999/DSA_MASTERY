//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<int,int>mp;
    int l=0,r=0;
    int max_len=-1,len=0;
    
    while(r<s.length())
    {
        mp[s[r]]++;
       
        
        
        if(mp.size()>k)
        {
            mp[s[l]]--;
            if(mp[s[l]]==0)
            {
                mp.erase(s[l]);
            }
            l++;
        }
         if(mp.size()==k)
        {
            len = r-l+1;
            max_len = max(len,max_len);
            
        }
        r++;
        
    }
    // if(mp.size()<k)
    // return -1;
    return max_len;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends