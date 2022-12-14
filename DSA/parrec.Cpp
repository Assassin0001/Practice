#include <iostream>
using namespace std;

void summ(int,int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Sum is:- ";
	summ(n,0);
}

void summ(int i,int sum){
	if(i < 1){
      cout<<sum<<" ";
	  return ;
	}
	summ(i-1,sum+i);

}