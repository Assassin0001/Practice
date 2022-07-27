//Reverse a 32-bit number
#include<iostream>
#include<math.h>
using namespace std;


int main(){
    int n;
    cin>>n;    
    int i =0;
    int ans=0;     
    while(n!=0){
    
    int digit=n%10;
    ans = (ans*10)+digit;
    n/=10;
    i++;  
    }
    cout<<ans;  
    return 0;
}