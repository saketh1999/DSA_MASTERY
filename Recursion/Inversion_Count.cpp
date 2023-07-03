//Link: https://www.codingninjas.com/studio/problems/number-of-inversions_6840276?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

//code:
    long long int merge_helper(vector<int>&arr,long long  int s,long long int  e)
    {
        long long  int mid=s+(e-s)/2;
         int count=0;
        
        long long  int len1=mid-s+1;
        long long  int len2=e-mid;
        
        long long  int *first = new long long int [len1];
        long long  int *second = new long long int [len2];
        
        //adding in
        long long  int starting_index=s;
        
        for(long long int i=0;i<len1;i++)
        {
            first[i]=arr[starting_index++];
        }
        starting_index=mid+1;
        for(long long int i=0;i<len2;i++)
        {
            second[i]=arr[starting_index++];
        }
        
        //Merging the two array
        long long  int index1=0;
        long long  int index2=0;
        starting_index=s;
        while(index1<len1 && index2<len2)
        {
            if(first[index1]<=second[index2])
            {
                arr[starting_index++]=first[index1++];
              
            }
            else{
                arr[starting_index++]=second[index2++];
                count+=(len1-index1);
            }
        }
        while(index1<len1)
        {
             arr[starting_index++]=first[index1++];
        }
        while(index2<len2)
        {
            arr[starting_index++]=second[index2++];
        }
        return count;
        
    }
    
    long long int mergeSort(vector<int> &arr,long long int  s,long long int e)
    {
        int count=0;
        if(s>=e)
        return count;
        long long   int mid=(e-s)/2+s;
        
        count+=mergeSort(arr,s,mid);
        
        count+=mergeSort(arr,mid+1,e);
        
        count+=merge_helper(arr,s,e);
        
    }

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    long long int N=n-1;
    mergeSort(a,0,N);
}