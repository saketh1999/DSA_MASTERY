//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
         int d =n&(~n+1);
         int i=0;
         while(d)
         {
             d=d>>1;
             i++;
         }
         return i;
        
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends