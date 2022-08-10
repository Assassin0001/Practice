#include <iostream>
using namespace std;

int cnt=0;
void count(int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Numbers are:- ";
	count(n);
}

void count(int n){
	cnt = n;
	if(cnt < 1){
	  return ;
	}
	cout<<cnt<<" ";
	count(n-1);
}