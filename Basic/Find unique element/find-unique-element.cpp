//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findUnique(int a[], int n, int k) {
     
        sort(a,a+n);
        //for(int i=0;i<n;i++)
      //  cout<<a[i]<<" ";
        
        for(int i=0;i<n;)
        {
            if(a[i]!=a[i+k-1])
            return a[i];
            
            else
            {
                i=i+k;
            }
            
        }
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.findUnique(a, n, k) << endl;
    }
}
// } Driver Code Ends