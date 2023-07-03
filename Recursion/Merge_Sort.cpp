#include <iostream>
using namespace std; 

void do_merge(int *arr,int s,int e)
{
    int mid= (s+e)/2;
    
    int len1= mid-s+1;//lenght of the first array
    int len2 = e-mid;//lenght of the second array

    int *first = new int[len1];//creating first array
    int *second = new int[len2]; // Creating the second array

    //copying the two arrays from the main array
    //1
    int starting_index=s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[starting_index++];
    }
    //2
    starting_index=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[starting_index++];
    }

    //now merge
    int index1=0;
    int index2=0;
    starting_index=s;
    //start merging
    while(index1<len1 && index2 <len2)
    {
        if(first[index1]<second[index2])
        {
            arr[starting_index++]=first[index1++];
        }
        else
        {
            arr[starting_index++]=second[index2++];
        }
    }
    //if any element remaining

    while(index1<len1)
    {
        arr[starting_index++]=first[index1++];
    }
    while (index2<len2)
    {
        arr[starting_index++]=second[index2++];
    }
    //delete the dynamically allocated memory
    delete [] first;
    delete [] second;
    

}


void MergeSort(int *arr,int s,int e)
{
    if(s>=e)
    return;

    int mid=(s+e)/2;
    //left part sort
    MergeSort(arr,s,mid);
    //right part sort
    MergeSort(arr,mid+1,e);

    //Now merge the two parts back together
    do_merge(arr,s,e);

}


int main()
{
   int arr[]={4,1,3,9,7};  
    int  n=5;

    MergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}