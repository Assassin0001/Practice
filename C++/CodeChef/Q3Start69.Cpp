#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	 int n;cin>>n;
	 int arr[100000];
	 int cnt = 0;
	 for(int i=0;i<n;i++){
	     cin>>arr[i];
	 }
	 sort(arr,arr+n);
     for(int i=0;i<n;i++){
        if(arr[i]!=i+1 && arr[i]<i+1){
            cnt = cnt+(i+1-arr[i]);
        }
        else if(arr[i]>i+1){
            cnt =-1;
            break;
        }
     }
     cout<<cnt<<endl;
	}
	return 0;
}

