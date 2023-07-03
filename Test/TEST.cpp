
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //Bit Manupulation check
    // signed int i = 60;
    // i= i>> 2;
    // if(i>0)
    // cout<<i;
    // else
    // cout << ~i;

    //pointers check
    int *p;
    p=new int[2];
    p[0]=43;p[1]=3;
    cout<<p<<" "<<p[1];

}