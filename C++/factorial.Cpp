#include <iostream>
using namespace std;

int fact(int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Factorial is:- ";
	cout<<fact(n);
}

int fact(int i){
	if(i == 1){
	  return 1;
	}
	return i*fact(i-1);

}