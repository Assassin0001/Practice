// Only return one of the possible subsequences with sum K

#include <bits/stdc++.h>
using namespace std;

bool printSum(int ind, vector<int>& ds,int s, int sum,int* arr,int n){
    if(ind == n){
        //condition satisfied
        if(s == sum){
            for(auto it:ds) cout<< it<<" ";
            cout<<endl;
            return true;
        }
        //condition not satisified
        else return false;
    }
    //pick element
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printSum(ind+1,ds,s,sum,arr,n) == true) return true;

    s-=arr[ind];
    ds.pop_back();

    //not pick element
   if(printSum(ind+1,ds,s,sum,arr,n) == true) return true;
   return false;
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