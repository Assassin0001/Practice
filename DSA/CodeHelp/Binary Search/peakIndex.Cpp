#include <bits/stdc++.h>
using namespace std;

int peakInd(vector<int> &arr){
	int start = 0;
	int end = arr.size()-1;
	int mid = start+(end-start)/2;
    // Start < End  and not start<=end as it goes into a loop.
    while(start<end){
          if(arr[mid]<arr[mid+1]) start=mid+1;
          else{
            end = mid;
          }
          mid = start + (end-start)/2;
    }
    return mid;
}

int main(){
	vector<int> arr;
     arr.push_back(0);
     arr.push_back(1);
     arr.push_back(3);
     arr.push_back(2);
     arr.push_back(0);
    int m=peakInd(arr);
    cout<<"Peak Index of Array is "<<m;
    return 0;
}