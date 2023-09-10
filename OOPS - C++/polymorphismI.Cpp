#include <iostream>
#include "Hero.cpp"
using namespace std;

//Polymorphism- 
//Static: Function Overloading && Operator Overloading
//Dynamic: Function Overriding
class Human{
    public: 
        int height;
        int weight;
        int age;

        //Function Overloading - Same Function Name | Parameters:  Datatype , Quantity Changes 
        void setDetails(int ht){
            this->height = ht;
        }
        
        void setDetails(int ht, int wt){
            this->height = ht;
            this->weight = wt;
        }

        void setDetails(int ht, int wt, int age){
            this->height = ht;
            this->weight = wt;
            this->age = age;
        }
};

//Static Polymorphism
class Complex{
    private:
        int real,img;

    public:
        Complex(int r=0, int i=0){
            real = r;
            img = i;
        }    

        //Operator Overloading
        Complex operator+(Complex const& obj){
            Complex res;
            res.real = real+ obj.real;
            res.img = img + obj.img;
            return res;
        }

        void print(){
            cout<<real<< "+i"<<img<<"\n";
        }
};

int main(){
   //Function Overloading
   Human *obj1 = new Human();
   obj1->setDetails(155);
   obj1->setDetails(155, 45, 20);
   obj1->setDetails(155, 45);
   
    //Operator Overloading
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}