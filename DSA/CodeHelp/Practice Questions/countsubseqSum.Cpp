#include <bits/stdc++.h>
using namespace std;

int printSum(int ind,int s, int sum,int* arr,int n){
    //Only for positive number array
    if(s > sum) return 0;
    if(ind == n){
        //condition satisfied
        if(s == sum) return 1;
        //condition not satisified
        else return 0;
    }
    //pick element
    s += arr[ind];

    int l = printSum(ind+1,s,sum,arr,n);

    s-=arr[ind];

    //not pick element
    int r = printSum(ind+1,s,sum,arr,n);
    return l+r;
}

int main(){
    cout<<"Enter length: ";
    int n;cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    cout<<"Enter sum: ";
    int sum;cin>>sum;
    cout<<printSum(0,0,sum,arr,n);

    delete []arr;
    return 0;
}