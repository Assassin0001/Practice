#include <iostream>
using namespace std;

int factorial(int);
int nCr(int,int);

int main(){
    int n,r,ans;
    cout<<"Enter number and its power coefficient:";
    cin>>n>>r;
    ans=nCr(n,r);
    cout<<ans;
}

int factorial(int n){
    int fact=1;
    for(int i=1;i<= n;i++){
        fact = fact *i;
    }
    return fact;
}
int nCr(int n,int r){
    int ans = 1;
    ans = factorial(n)/(factorial(r)*factorial(n-r));
    return ans;
}