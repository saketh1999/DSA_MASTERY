#include <iostream>
#include<set>
using namespace std;
void solve(string s, vector<char> aux, set<vector<char>> &ans,int i)
{
    if(i>=s.length())
    {
        if(aux.size())
        ans.insert(aux);
        return;
    }

    //exclude
    solve(s,aux,ans,i+1);

    //include
    aux.push_back(s[i]);
    solve(s,aux,ans,i+1);
}

int main(){
     string s= "aac";
    vector<char>aux;
    set<vector<char>> ans;//this will only store the unique elements

    solve(s,aux,ans,0);

    for(auto x : ans)
    {
        for(auto y:x)
        cout<<y<<" ";

        cout<<endl;
    }

}