#include <iostream>
using namespace std;
void printFromandTillN(int n)
{
    if(n==0)
    return;
    cout<<n<<" ";
     printFromandTillN(n-1);cout<<endl;
    cout<<n<<" ";
  
}

// void printTillN(int start,int n)
// {
//     if(start==n+1)
//     return;
//     cout<<start<<" ";
//     return printTillN(start+1,n);
// }

int main()
{
    int n;
    cin>>n;
    cout<<endl;
    printFromandTillN(n);
    // cout<<endl;
    // printTillN(1,n);
}