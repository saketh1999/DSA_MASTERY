#include <iostream>
using namespace std;
bool binary_search(int arr[],int key,int left,int right, int mid)
{
    if(left>right)
    {
        return false;
    }
    //cout<<arr[mid]<<" ";//debug
    if(arr[mid]==key)
    return true;

    else if (arr[mid]<key)
    {
        
        return binary_search(arr,key,mid+1,right,((mid+1)+right)/2);
    }
    else{
      return binary_search(arr,key,left,mid-1,((mid-1)+left)/2);
    }

}
int main()
{
    int arr[]={1,2,3,4,5};
    int key; cin>>key;

    int size=sizeof(arr)/sizeof(arr[0]);
    int right=size-1;
    int left = 0;
    int mid=(left+right)/2;
    bool found = binary_search(arr,key,left,right,mid);
    cout<<endl;
    if(found)
    {
        cout<<"Found";
    }
   else{
    cout<<"Not Found";
   }
}