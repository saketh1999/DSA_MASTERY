#include <iostream>
using namespace std;
bool linearsearch(int arr[],int size,int x)
{
    if(size==-1)
    return false;

    if(x==arr[size])
    return true;
    else{
        return linearsearch(arr,size-1,x);
    }
}
int main()
{
    int x; cin>>x;
    int arr[]={5,23,54,1,20};

    int size=sizeof(arr)/sizeof(arr[0]);

    bool found= linearsearch(arr,size-1,x);
    if(found)
    cout<<"Found it";
    else 
    cout<<"Didnt find it";

}