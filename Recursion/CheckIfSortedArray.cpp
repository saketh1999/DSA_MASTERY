#include<iostream>
using namespace std;
bool Array_check(int arr[],int last_ind,int prev)
{
    if( last_ind==-1)
    {
        return true;}

    int x=arr[last_ind];
    if(x<prev)
    {
        prev=x;
    return Array_check(arr,last_ind-1,prev);
    }
    else{ return false;}
}
int main()
{

int arr[]={6,4,2,1,9};//returns 0 (false)
int arr1[]={1,2,3,4,5};//returns 1 (true)
int prev=INT_MAX;
int size=sizeof(arr1)/sizeof(arr1[0]);
bool check = Array_check(arr1,size-1,prev);
cout<<endl<<check;
}