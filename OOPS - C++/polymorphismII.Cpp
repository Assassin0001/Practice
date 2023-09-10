#include<bits/stdc++.h>
using namespace std;

//Dynamic | Runtime Polymorphism
class Database{
    public:
        //Virtual Function
        virtual void show(){
            cout<<"Show Parent Class"<<endl;
        }
        
        //Do nothing Function {Pure Virtual Function}
        virtual void getName() = 0;

        //void show() { cout << "show base class\n"; }
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