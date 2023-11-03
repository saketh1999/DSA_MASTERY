#include <iostream>
using namespace std;
void pass_ref(vector<int> &ans)
{
        if(ans.size()>200)
    {cout<<"THIS SIZE = "<<ans.size()<<endl;
        return;}

    for(int i=0;i<100;i++)
    ans.push_back(i);

    pass_ref(ans);
    cout<<"THIS SIZE2 = "<<ans.size()<<endl;
    cout<<"Vectors -> 150th value"<<ans[150]+1<<endl;
}
void pass_val(vector<int> ans)
{
    if(ans.size()>200)
    {cout<<"THIS SIZE = "<<ans.size()<<endl;
        return;}
    for(int i=0;i<100;i++)
    {ans.push_back(i);}

    pass_val(ans);
    cout<<"THIS SIZE2 = "<<ans.size()<<endl;
    cout<<"Vectors -> 150th value"<<ans[150]+1<<endl;
}

int main()
{
    vector<int> ans;

    pass_val(ans);
    cout<< ans.size();
    cout<<endl;
    pass_ref(ans);
    cout<< ans.size();
    cout<<endl;
}