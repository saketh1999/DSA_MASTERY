#include<iostream>
using namespace std;
string reverse_same(string ip, int st,int en)
{
    if(st>en)
    return ip;

    swap(ip[st],ip[en]);
    return reverse_same(ip,st+1,en-1);

}
string reverse(string ip,string op,int n)
{
    if(n==-1)
    return op;

    op+=ip[n];
    return reverse(ip,op,n-1);

}
int main()
{
    string ip="saketh";
    //if O(N) is allowed
    // string op="";

    // int n=ip.length();

    // op = reverse(ip,op,n-1);
    // cout<<op;

    //If O(N) not allowed
    int n=ip.length();
    string op=reverse_same(ip,0,n-1);
    cout<<op;

}