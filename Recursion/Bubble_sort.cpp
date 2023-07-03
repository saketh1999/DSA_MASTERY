#include<iostream>
using namespace std;
void bubble_helper(int arr[],int n,int j)
{
    if(j>=n)
    return;

    if(arr[j]>arr[j+1])
    swap(arr[j],arr[j+1]);
    return bubble_helper(arr,n,j+1);

}
void bubble_rec(int arr[],int n)
{
    if(n==0 || n==1)
    return ;

    //sort 1 element in one recursive call

    //All for loops can be converted to a recursive call function
    // for(int j=0;j<n;j++)
    // {
    //     if(arr[j]>arr[j+1])
    //     swap(arr[j],arr[j+1]);
    // }
    bubble_helper(arr,n,0);

    //recursive call
    return bubble_rec(arr,n-1);

}
int main()
{
    int arr[]={5,2,3,1};

    int size=sizeof(arr)/sizeof(arr[0]);

    bubble_rec(arr,size);

    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
}