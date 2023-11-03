//creating a seperate hero class file
#include <iostream>
using namespace std;
// class Hero{
//     //properites
// public: //to access with object
// int health;
// char level;
// };

//To understand getter and setters
class Hero{
    //properites

int health;

public:
static int time;//a static variable
 //to access with object
//this is a default constructor defined by user
Hero(){
    cout<<"Constructor Created"; //make sure that using namespace is present to do this
}

 Hero(int health,int level)
{
    this->health=health;
    this->level=level;
    
}
static int R_time()
{
    return time;
}
char level;

int getHealth()
{
    return health;
}

char getLevel()
{
    return level;
}

 void setHealth(int health)
{
  this->/*this will give the variable of class*/health=health/*this is the passed value*/;   
}
void setLevel(int level)
{
    this->level = level;
}

};