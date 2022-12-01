#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int cnt[10001]={0};
	    for(int i=0;i<n;i++){
	        int x;cin>>x;
	        if(cnt[x]==0) cnt[x]++;
	        else cnt[x]--;
	    }
       for(int i=0;i<10001;i++){
           if(cnt[i]!=0){ 
               cout<<i<<endl;
               break;
           }
       }	   
	}
	return 0;
}
