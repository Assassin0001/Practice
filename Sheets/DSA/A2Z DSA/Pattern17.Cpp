#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int i=1;
  while(i<=n){
    int j=1;
    char value='D'-i+1; //To declare first row element as 'D'.
    while(j<=i){
        cout<<value<<" ";
        j++;
        value++;
    }
    cout<<endl;
    i++;
  }
  return 1;
}
