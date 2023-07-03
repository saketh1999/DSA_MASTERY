#include <iostream>
using namespace std;
void solve(string s,int arr[2], int i,int element)
{
    if(i>=s.length())
    {
        return;
    }
    if(element==s[i])
    {
        if(arr[0]==-1)
        {
            arr[0]=i;
        }
        else{
            arr[1]=i;
        }
    }
    solve(s,arr,i+1,element);
    

}
int main()
{
    string s="abaacdaefaah";
    char element='a';
    int arr[2]={-1,-1};
    solve(s,arr,0,element);
    cout<<arr[0]<<" "<<arr[1];

}