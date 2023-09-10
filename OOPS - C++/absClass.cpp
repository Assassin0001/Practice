#include<bits/stdc++.h>
using namespace std;

//Abstract Class
class Database{
    public:
        // Abstract Class : 
        // i) must have atleast one Pure Virtual Function
        // ii) cannot have object, but have pointers
        
        // Non Virtual Function
        void show() { cout << "show base class\n"; }
        
        //Do nothing Function {Pure Virtual Function}
        virtual void getName() = 0;
};

class Manager: public Database{
    public:
    void getName(){
        cout<<"This is Manager class"<<endl;
    }

    void show(){
        cout<<"Manager Show class"<<endl;
    }
};

class Accountant: public Database{
    public:
    void getName(){
        cout<<"This is Accountant class"<<endl;
    }
};

class Customers: public Database{
    public:
    void getName(){
        cout<<"This is Customer class"<<endl;
    }
};

int main(){
    //Virtual Function
    Database *ptr;
    Manager m;
    ptr = &m;
    ptr->getName();
    ptr->show();
}