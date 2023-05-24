#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int i=1;
  while(i<=n){
    int j=1;
    char value='A'+i-1; //To declare first row element as 'A'.
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
