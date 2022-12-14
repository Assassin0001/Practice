#include <iostream>
using namespace std;

int fibo(int);

int main(){
    int n,ans;
    cout<<"Enter number:";
    cin>>n;
    ans=fibo(n);
    cout<<"The nth term of fibonacci is "<<ans;
    return 0;
}

int fibo(int n){
    int sum;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int first=0;
    int second=1;
    for(int i=2;i<n;i++){
        sum = first+second;
        first=second;
        second=sum;
    }
    return sum;
}