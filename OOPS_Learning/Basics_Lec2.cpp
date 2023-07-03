#include <iostream>
#include "Human.cpp"
using namespace std;

int main()
{
    Male M;
    M.setAge(23);
    M.setHeight(185);
    M.setWeight(120);
    cout<<"Height = "<<M.getHeight()<<endl;
    cout<<"Age = "<<M.getAge()<<endl;
    cout<<"Weight = "<<M.getWeight()<<endl;

    //M.color="Wheatish";//since the property is public
    M.setColor("Wheatish");
    string Color_of_Male=M.getColor();
    cout<<"Color = "<<Color_of_Male<<endl;
    M.sleep();



}