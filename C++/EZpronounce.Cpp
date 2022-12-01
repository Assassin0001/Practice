#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;int count=0;
	    string str;
	    cin>>n>>str;
        for(int i=0;i<n;i++){
        if(str[i] == 'a' || str[i]=='e' || str[i]=='i' || str[i]=='o'|| str[i]=='u'){
            count=0;
            continue;
        }
        else{ 
            count++;
            if(count == 4)
            break;
            }
        }
	if(count < 4){ 
	    cout<<"Yes"<<endl;
	}
	else{ 
	    cout<<"No"<<endl;
	    }
	}
	return 0;
}