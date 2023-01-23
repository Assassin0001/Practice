#include <bits/stdc++.h>
using namespace std;

void printSum(int ind, vector<int>& ds,int s, int sum,int* arr,int n){
    if(ind == n){
        if(s == sum){
            for(auto it:ds) cout<< it<<" ";
            cout<<endl;
        }
        return;
    }
    //pick element
    ds.push_back(arr[ind]);
    s += arr[ind];

    printSum(ind+1,ds,s,sum,arr,n);

    s-=arr[ind];
    ds.pop_back();

    //not pick element
    printSum(ind+1,ds,s,sum,arr,n);
}

int main(){
    cout<<"Enter length: ";
    int n;cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    vector<int> ds;
    cout<<"Enter sum: ";
    int sum;cin>>sum;
    printSum(0,ds,0,sum,arr,n);

    delete []arr;
    return 0;
}