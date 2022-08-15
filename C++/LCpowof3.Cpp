#include<iostream>
using namespace std;

bool isPowerOfThree(int n){
    if(n<=1){
        return n == 1;
    }
    return n%3 == 0 && isPowerOfThree(n/3);
}

int main(){
    int n;
    cin>>n;
    cout<<isPowerOfThree(n);
}

// Loops 
/**
if(!n) return false;
while(n%3 == 0) n/=3;
     return n
     ==1;
     **/