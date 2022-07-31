#include <iostream>
using namespace std;

bool isPrime(int);

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    if(isPrime(n)){
        cout<<n<<" is Prime number.";
    }
    else{
        cout<<n<<" is not Prime number.";
    }
    return 0;
}

bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
          return false;
        }
        return true;    
    }
}