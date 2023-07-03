#include <iostream>
#include "Hero.cpp" //this is helping to communicate with the other file Hero.cpp
//What #include will do it is , during compilation it will past all the code in other files in 
//this file and will act as one.

using namespace std;

int Hero :: time=10;

int main()
{

    //creation of object (Statically)
    Hero h3(100,'A');
    cout<<"Health = "<<h3.getHealth()<<endl;
    cout<<"Level = "<< h3.getLevel()<<endl;

    //copy constructor
    Hero h4(200,'B');
    cout<<"Health = "<<h4.getHealth()<<endl;
    cout<<"Level = "<< h4.getLevel()<<endl;

    //copy assignment operator
    h4=h3;//all values of h3 will be copied to h4
    cout<<"Health = "<<h4.getHealth()<<endl;
    cout<<"Level = "<< h4.getLevel()<<endl;

    //Static Variable printing
    cout<<"Time1 = "<<Hero::time<<endl;//Good Practice
    cout<<"Time2 = "<<h3.time<<endl;//Bad Practice
    cout<<"Time3 = "<<h4.time<<endl;//Bad Practice

    //static function -> is a function of the class
    cout<<Hero::R_time()<<endl;
    /*


    //creation of object (Statically)
    Hero h1;
    // using setter and getter

    h1.setHealth(5); 
    h1.setLevel('4');

    cout<<"HEALTH = "<< h1.getHealth()<<endl;
    cout<<"Level = "<< h1.getLevel()<<endl;


    //dynamic allocation
    Hero *h2 =new Hero;
    //h2 -> will store the location of the start point of the memory allocation

    h2->setHealth(5);
    h2->setLevel('8');

    cout<<"Health = "<< h2->getHealth()<<endl;
    cout<<"Level = "<< h2->getLevel()<<endl;

    //OR can do the same using deference operator
    cout<<"Health = "<< (*h2).getHealth()<<endl;
    cout<<"Level = "<< (*h2).getLevel()<<endl;

    //if you want to access a property
    h2->level='9';

    // h1.health=100;
    // h1.level ='3';

    // cout<<"health = " <<h1.health<<endl;
    // cout<<"level = "<<h1.level;



    */
    

    return 0;
}