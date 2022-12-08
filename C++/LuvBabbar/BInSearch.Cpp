#include <iostream>
using namespace std;

int binSearch(int arr[],int size,int key){
	int start = 0;
	int end = size-1;
    int mid = start+(end-start)/2;	
    while(start<=end){        
          if(arr[mid] == key) return mid;
          if(key > arr[mid]) start=mid+1;
          else end=mid-1;
          mid = start+(end-start)/2;
    }
    return -1;
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