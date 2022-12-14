#include <iostream>
using namespace std;

int cnt=0;
void count();

int main(){
	cout<<"Print Name 5 times:- "<<endl;
	count();
}

void count(){
	if(cnt >= 5){
	  return ;
	}
	cout<<"DeKU"<<" ";
	cnt++;
	count();
}