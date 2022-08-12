#include<iostream>
using namespace std;

int fibRec(int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is:- ";
    cout<<fibRec(n);

}

int fibRec(int n){
    if(n <= 1){
        return n;
    }
    return fibRec(n-1)+fibRec(n-2);
}

    