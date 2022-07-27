//Complement of Base 10 Integer
#include<iostream>
#include<math.h>
using namespace std;


int main(){
    int n;
    cin>>n;    
    
    int m=n;
    int mask=0;
    if(n==0){
        cout<<1;
    }
    else{
    while(m!=0){
        mask= (mask<<1) |1;
        m=m>>1;
    }
    int ans= mask&(~n);
    cout<<ans;
    }
    return 0;
}