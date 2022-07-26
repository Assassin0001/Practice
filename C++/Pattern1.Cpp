#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<i;
    }
    cout<<endl;
  }
  cout<<"\n";
  int i=1;
  while(i<=n){
    int j=1;
    while(j<=n){
        cout<<i;
        j++;
    }
    cout<<endl;
    i++;
  }
  return 1;
}
