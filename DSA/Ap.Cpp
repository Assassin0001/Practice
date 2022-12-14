#include <iostream>
using namespace std;

int apTerm(int);

int main(){
    int n,ans;
    cout<<"Enter number:";
    cin>>n;
    ans=apTerm(n);
    cout<<"The nth term of A.P. is "<<ans;
    return 0;
}

int apTerm(int n){
    return 3*n+7;
}