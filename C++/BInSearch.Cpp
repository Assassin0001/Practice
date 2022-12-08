#include <iostream>
using namespace std;

int binSearch(int arr[],int size,int key){
	int start = 0;
	int end = size-1;
	int mid = start+(end-start)/2;
	int ans=-1;
    while(start<=end){
          if(key>arr[mid]) start=mid+1;
          else if(key<arr[mid]) end=mid-1;
          else{
          	ans = mid;
          	return ans;
          } 
          mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int n,k;cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
	 cin>>arr[i];
	}
    cout<<binSearch(arr,n,k);
    return 0;
}