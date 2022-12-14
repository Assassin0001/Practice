#include <iostream>
using namespace std;

void count(int,int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Numbers are:- ";
    int i= 1;
	count(n,i);
}

void count(int n,int i){
	if(i > n){
	  return ;
	}
	count(n,i+1);
    cout<<i<<" ";
}