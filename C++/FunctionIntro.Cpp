#include <iostream>
using namespace std;

int power(int*,int*);

int main(){
    int a,b,ans;
    cout<<"Enter number and its power coefficient:";
    cin>>a>>b;
    ans=power(&a,&b);
    cout<<ans;
    return 0;
}

int power(int*a,int*b){
    int ans=1;
    for(int i=1;i<= *b;i++){
        ans = ans* *a;
    }
    return ans;
}