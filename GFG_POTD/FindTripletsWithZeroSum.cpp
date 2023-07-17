//GFG : https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
//Approach -> 1. Sort the array, and then use start and end pointers similar to two sum
////////////////////////////////////////////////
/*
                SOLUTION 
*/
////////////////////////////////////////////////
//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
      
        for(int i=0;i<n;i++)
        {
            for( int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }

        
        for(long long int i=0;i<n;i++)
        {
            long long int target=-1*arr[i];
            long long int start=i+1;
            long long int end=n-1;

            while(start<end)
            {
                if(arr[start]+arr[end]==target)
                {return true;}
                else if(arr[start]+arr[end]>target)
                {
                    end--;
                }
                else if(arr[start]+arr[end]<target)
                {
                    start++;
                    
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends