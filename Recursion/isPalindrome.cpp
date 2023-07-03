#include<iostream>
using namespace std;
bool check_pali(string s,int l,int r)
{
    if(l>=r)
    return true;

    if(s[l]!=s[r])
    return false;
    else{
        
        return check_pali(s,++l,--r);
    }
    
}
int main()
{
    string s="MALAYALAM";

    if(check_pali(s,0,s.length()-1))
    cout<<s<<" "<<"It is a Palindrom";

    else cout<<s<<" "<<"Not Palindrome";
}