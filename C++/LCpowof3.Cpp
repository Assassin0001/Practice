#include<iostream>
using namespace std;

bool isPowerOfThree(int n){
    if(n<=1){
        return n==1;
    }
    return n%3==0 && isPowerOfThree(n/3);
}

int main(){
    int n;
    cin>>n;
    cout<<isPowerOfThree(n);
}