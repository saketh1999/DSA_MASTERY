//Here we will Learn about Euclidean Algorithm
//Source GFG:https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
//This Algo is all about finding the GCD of two numbers

#include <iostream>

using namespace std;
int gcd_extended(int a,int b , int *x, int *y)
{
    if(a==0)
    {
        *x=0;
        *y=0;
        return b;
    }
    

    int x1,y1;
    int gcd=gcd_extended(a%b,a,&x1,&y1);

    *x=y1-(b/a) *x1;
    *y=x1;
    return gcd;
}

int gcd(int a, int b){
    if(a==0)
    return b;
    return gcd(b%a,a);
}

int main()
{
    int a,b;
    cout<<"Enter two numbers you want to find the GCD for "<<endl;

    cin>>a>>b;
    cout<<endl;
    int l,s;
    if(a>b){l=a,s=b;}
    else{l=b,s=a;}
    int x,y;
    cout<<"GCD for the two numbers is "<< gcd(l,s);
    //cout<<"GCD for the two numbers is "<< gcd_extended(l,s,&x,&y)<<endl;
}