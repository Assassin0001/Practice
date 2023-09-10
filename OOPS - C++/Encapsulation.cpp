#include <iostream>
using namespace std;

class Hero{
    //Encapsulation ->  All data members are private && functions are public 
    private:
    int health;

    public:
    //Constructor
    Hero(){
        cout<<"Constructor Called"<<endl;
    }

    //Variable scoping || Parameterised constructor
    Hero(int health){
        cout<<"Parameterised Constructor Called"<<endl;
        this->health = health;
    }

    // Public Properties
    int lvl;
    string name;
    char rank;

    //Setter
    void setHealth(int h){
        health = h;
    }
    //Getter
    int getHealth(){
        return health;
    }
};