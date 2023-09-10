#include <iostream>
#include "Hero.cpp"
using namespace std;

class Human{
    protected: 
        int height;
        int weight;
        int age;

    public:
        int getAge(){
            return this->age;
        }

        void setAge(int age){
            this->age = age;
        }

        int getW(int W){
            return this->weight;
        }

        int setW(int W){
            cout<<"Base Class"<<endl;
            this->weight = W;
        }

};

class Male: public Human{
    public:
    string color;

    Male(int ht, int wt, int age, string cl){
        this->height = ht;
        this->weight = wt;
        this->age = age;
        this->color = cl;
    }

    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }

    int getHeight(){
        return height;
    }
    int getAge(){
        return age;
    }
    int getWeight(){
        return weight;
    }

    void setWeight(int W){
        cout<<"Derived Class "<<endl;
        this->weight = W;   
    }
};

class Female: public Human{
    public:
    string color;
    
    void sleep(){
        cout<<"Male Sleeping"<<endl;
    }

    int getHeight(){
        return height;
    }
    int getAge(){
        return age;
    }
    int getWeight(){
        return weight;
    }

    void setWeight(int W){
        cout<<"Derived Class "<<endl;
        this->weight = W;   
    }
    
};

int main(){
   //Inheritance 
   //Types: Simple | Multiple | Multilevel | Hierarchical | Hybrid
   //Simple
   Male *obj1 = new Male(155,45,20, "black");

   cout<<obj1->getHeight()<<endl;
   cout<<obj1->getAge()<<endl;
   cout<<obj1->getWeight()<<endl;
   cout<<obj1->color<<endl;
   obj1->setWeight(45);
   cout<<obj1->getWeight()<<endl;

   Female* obj2 = new Female();
   cout<<obj1->getHeight()<<endl;
}