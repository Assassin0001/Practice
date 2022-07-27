#include <iostream>
using namespace std;

int main(){
    int n,rem;
    cin>>n;
    int sum =0;
    int prod=1;
    while(n!=0){
      rem=n%10;
      sum+=rem;
      prod*=rem;
      n=n/10;
    }
    cout<<sum<<" "<<prod;
    return 1;
}