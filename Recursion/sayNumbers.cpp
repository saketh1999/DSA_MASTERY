#include <iostream>
using namespace std;

void print_digit(int n)
{
    if(n==0)
    cout<<"Zero ";
    if(n==1)
    cout<<"One ";

    if(n==2)
    cout<<"Two ";
        if(n==3)
    cout<<"Three ";
        if(n==4)
    cout<<"Four ";
        if(n==5)
    cout<<"Five ";
        if(n==6)
    cout<<"Six ";
        if(n==7)
    cout<<"Seven ";
        if(n==8)
    cout<<"Eight ";
        if(n==9)
    cout<<"Nine ";
}
void cal_digits(int n)
{//432
if(n==0)
{
    return;
}
int x=n%10;
cal_digits(n/10);
print_digit(x);
return;
    
}

int main()
{
    int n;
    cin>>n;
    if(n==0)
    cout<< "Zero ";
    else
    cal_digits(n);
}