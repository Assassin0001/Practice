#include <iostream>
using namespace std;

bool iseven(int*);

int main(){
    int a;
    cout<<"Enter number to check:";
    cin>>a;
    if(iseven(&a))
       cout<<"No. is even";
    cout<<"No. is odd";   
    return 0;
}
bool iseven(int*a){
    if (*a & 1)
        return false;
    return true;
}