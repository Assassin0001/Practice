#include <iostream>
using namespace std;

int summ(int);

int main(){
    int n;
    cout<<"Enter No.";
    cin>>n;
	cout<<"Sum is:- ";
	cout<<summ(n);
}

int summ(int i){
	if(i ==0){
        return 0;
	}
	return i+summ(i-1);

}