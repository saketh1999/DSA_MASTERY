//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here // Your code here
         m=(l+r)/2;
         int l1 = m-l+1;
         int l2 = r-m;
         int *l_arr = new int[l1];
         int *r_arr = new int[l2];
         
         int s=l;
         for(int i=0;i<l1;i++)
         {
             l_arr[i]=arr[s++];
             
         }
         s=m+1;
         for(int i=0;i<l2;i++)
         {
             r_arr[i]=arr[s++];
             
         }
         
         //Now merge
         s=l;
         int ind1 = 0 ;int ind2 =0 ;
         while(ind1<l1 && ind2<l2)
         {
            
             if(l_arr[ind1] < r_arr[ind2])
             {
                 arr[s++] = l_arr[ind1++];
             }
             else {
               
                  arr[s++] = r_arr[ind2++];
                 
             }
         }
         
         while(ind1<l1)
         {
              arr[s++] = l_arr[ind1++];
         }
         
         while(ind2<l2)
         {
             arr[s++] = r_arr[ind2++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code 
        if(l>=r)
        return;
        
       int mid = (l+r)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends