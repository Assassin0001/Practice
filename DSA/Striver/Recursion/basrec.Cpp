#include <iostream>
using namespace std;

int cnt=0;
void count();

int main(){
	cout<<"1-Digit Numbers :-";
	count();
}

void count(){
	if(cnt >= 10){
	  return ;
	}
	cout<<cnt<<" ";
	cnt++;
	count();
}