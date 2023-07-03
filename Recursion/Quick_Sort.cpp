#include <iostream>
using namespace std;
int partition (int *arr,int s,int e)
{
    int pivot=arr[s];//1. get the pivot (first element)

    int count=0;//2.variable to count the number of elements less than pivot
    for(int i=s+1;i<=e;i++)//i<=e since e -> is not out of bound value
    {
        if(arr[i]<=pivot)
        count++;
    }

    //3. place pivot element at the correct position
    int pivot_index=s+count;
    swap(arr[s],arr[pivot_index]);
    
    //pivot=arr[pivot_index];//this is redundant since pivot element is still the same

    //4. making all elements to the left and right smaller and greater than pivot
    int i=s,j=e;
    while (i<pivot_index && j>pivot_index)
    {
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;
        if(i<pivot_index && j>pivot_index)
        {
            swap(arr[i],arr[j]);
            i++,j--;

        }

    }
    return pivot_index;
    

}
void quickSort(int *arr,int s,int e)
{
    //base condition
    if(s>=e)
    return ;

    //partition
    int p= partition(arr,s,e);

    //sort the first partion
    quickSort(arr,s,p-1);
    //sort the second partion
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[]={2,3,1,6,9,2,12,100,32,4,5,7};
    int n=12;

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}