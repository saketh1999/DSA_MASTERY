//this file will hold the class for Basics_lec2
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Human{

    int height;
    int weight;
    int age;

    public: 
    int getAge()
    {
        return this->age;
    }
    int getWeight()
    {
        return this->weight;
    }
        int getHeight()
    {
        return this->height;
    }
    int setWeight(int weight)
    {
        return this->weight=weight;
    }
        int setHeight(int height)
    {
        return this->height=height;
    }
        int setAge(int age)
    {
        return this->age=age;
    }
    
};

class Male : public Human{
    public:
    string color;
    
    void sleep(){
        cout<<"MALE Spleeping";
    }

    void setColor(string color)
    {
        this->color=color;
    }
    string getColor()
    {
        return this->color;
    }
};