/*We came across this algo while working on LC-169 Majority Element
link: https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
The Editorial has detail explanation but it is not good 
follow this explanation: https://www.youtube.com/watch?v=n5QY3x_GNDg
Majority element = an element that occurs more than n/2 times
Sol 2 step 
1. find a candidate
2.verify if candidate is the majority element
*/
#include <iostream>
#include <list>
using namespace std;

int main()

{
    list<int> v;
    //must make sure the majority element count > n/2
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(5);
    v.push_back(7);
    v.push_back(5);
    v.push_back(1);
    v.push_back(5);
    v.push_back(7);
    int count =0, cad;
    for(auto x:v)
    {
        if(count==0)
        cad=x;

        count+=(x==cad)?1:-1;
    }
    cout<<cad;
}