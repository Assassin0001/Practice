#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int x,y;
	    cin>>x>>y;
	    int max = x>y?x:y;
	    int min = x<y?x:y;
        int flag=0;
	    while(min<=max){
	        if(min==max){
	            cout<<"Yes"<<endl;
	            flag=1;
	        }
	        min*=2;
	    }
	    if(flag==0)
	     cout<<"No"<<endl;
	}
	return 0;
}
