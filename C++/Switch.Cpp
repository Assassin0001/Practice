#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter nos:-";
    cin>>a>>b;
    char op;
    cout<<"Enter operation you want to perform: ";
    cin>>op;
    switch(op){
        case '+':
         cout<<(a+b)<<endl;
         break;
        case '-':
         cout<<(a-b)<<endl;
         break;
        case '*':
         cout<<(a*b)<<endl;
         break;   
        case '/':
         cout<<(a/b)<<endl;
         break;         
        default :
        cout<<"Please enter valid operation.";
        break;       
    }
    return 0;
}