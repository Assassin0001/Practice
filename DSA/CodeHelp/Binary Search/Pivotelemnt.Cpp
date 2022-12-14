#include <bits/stdc++.h>
using namespace std;

int getpivot(vector<int> arr){
    int start=0;
    int end=arr.size()-1;
    while(start<end){
        int mid =start + (end-start)/2;
        if(arr[mid]>=arr[0]) start=mid+1;
        else{
            end=mid;
        }
    }
    return end;
}

int main(){
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(17);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    int p = getpivot(arr);
    cout<<p;
    return 0;
}