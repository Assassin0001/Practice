#include <bits/stdc++.h>
using namespace std;

int sqrtInt(int key){
	int start = 0;
	int end = key;
    int ans;
    int mid = start+(end-start)/2;	
    while(start<=end){        
          if(mid*mid == key) return mid;
          if(mid*mid > key) end=mid-1;
          else{
            ans=mid;
            start=mid+1;
          }
          mid = start+(end-start)/2;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    cout<<"Square Root of N is "<<sqrtInt(n);
}