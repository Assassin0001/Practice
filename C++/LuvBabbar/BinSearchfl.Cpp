#include <bits/stdc++.h>
using namespace std;

int firstoccur(int arr[],int size,int key){
	int start = 0;
	int end = size-1;
	int mid = start+(end-start)/2;
	int ans =-1;
    while(start<=end){
          if(arr[mid]<key) start=mid+1;
          else if(key<arr[mid]) end=mid-1;
          else{
            ans = mid;
            end=mid-1;
          }
          mid = start + (end-start)/2;
    }
    return ans;
}

int lastoccur(int arr[],int size,int key){
	int start = 0;
	int end = size-1;
	int mid = start+(end-start)/2;
	int ans =-1;
    while(start<=end){
          if(arr[mid]<key) start=mid+1;
          else if(key<arr[mid]) end=mid-1;
          else{
            ans = mid;
            start=mid+1;
          }
          mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int n,k;cin>>n>>k;
	int arr[5] = {1,3,3,4,5};
    int f=firstoccur(arr,n,k);
    int l=lastoccur(arr,n,k);
    cout<<"First, Last & Total No of occurences of key is "<<f<<" "<<l<<" "<<l-f+1<<endl;
    return 0;
}