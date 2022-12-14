#include <iostream>
using namespace std;

void count(int,int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Numbers are:- ";
    int i= n;
	count(n,i);
}

void count(int n,int i){
	if(i < 1){
	  return ;
	}
	count(n,i-1);
    cout<<i<<" ";
}