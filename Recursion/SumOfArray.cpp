#include <iostream>
using namespace std;

int sumOfElements(int arr[],int sum, int size )
{
    if(size==-1)
    return sum;
    //cout<<arr[size];
    sum=sum+arr[size];
    return sumOfElements(arr,sum,size-1);

}
int main()
{
int arr[]={3,2,5,1,6};
int sum=0;
int size=sizeof(arr)/sizeof(arr[0]);
int total= sumOfElements(arr,sum,size-1);
cout<<endl<<total;
}
