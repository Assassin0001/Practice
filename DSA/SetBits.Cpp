#include <iostream>
using namespace std;

int setBits(int);

int main(){
    int a,b,c1,c2,ans;
    cout<<"Enter number1:";
    cin>>a;
    cout<<"Enter number2:";
    cin>>b;   
    c1=setBits(a);
    c2=setBits(b);
    ans=c1+c2;
    cout<<"The sum of setBits is "<<ans;
    return 0;
}

int setBits(int n){
    int count=0;
    while(n!=0){
        if(n & 1){
            count++;
        }
        n=n>>1;
    }
    return count;
}