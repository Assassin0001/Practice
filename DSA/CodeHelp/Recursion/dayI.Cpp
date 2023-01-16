#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==1 || n == 0) return 1;
    else return n*fact(n-1);
}

int power(int n){
    if(n==0) return 1;

    int smallerProblem = power(n-1);
    int biggerProblem = 2 * smallerProblem;
    return biggerProblem;
}

void print(int n){
    if(n == 0) return;
    print(n-1);
    cout<<n<<" ";

}

int main(){
    cout<<"Enter Number : ";
    int n;cin>>n;
    cout<<"Factorial is: "<<fact(n)<<endl;
    cout<<"Enter Num: ";
    int x;cin>>x;
    cout<<"Power of 2 is:  "<<power(x)<<endl;
    cout<<"Enter nos to print: ";
    int y;cin>>y;
    cout<<"Print Nos ";
    print(y);
    return 0;
}