#include<iostream>
#include<thread>
#include <unistd.h>
using namespace std;
void t1()
{
    sleep(1);
    for(int i=0;i<10;i++)
    cout<<"A = "<<i<<endl;
    fflush(stdout);
}
void t2()
{
    sleep(1);
    for(int i=0;i<10;i++)
    cout<<"B = "<<i<<endl;
    fflush(stdout);
}
int main()
{
    //Code to do multi-threading in C++
    thread th1(t1);
    thread th2(t2);

    th1.join();
    th2.join();
    return 0;
}