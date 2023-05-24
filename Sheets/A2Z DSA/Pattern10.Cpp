#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int i=1;
  //char value='A';
  while(i<=n){
    int j=1;
    while(j<=n){
        char value='A'+i-1;      
        cout<<value<<" ";
        j++;
    }
    cout<<endl;
    //value=value+1;
    i++;
  }
  return 1;
}
