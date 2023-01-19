#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    //Base Case
    if(size == 0 || size == 1) return true;

    // Recursive Call
    if(arr[0] > arr[1] ) return false;
    else{
        bool ans = isSorted(arr+1,size -1);
        return ans;
    }
}

int sumArr(int arr[],int size){
    //Base Case
    if(size == 0) return 0;
    if(size == 1) return arr[0];

    //Recursive Call
    int remainder = sumArr(arr+1,size-1);
    int ans = arr[0] + remainder;
    return ans;
}

bool linsearch(int arr[],int size,int x){
    // Base Case
    if(size == 0) return false;
    if(arr[0] == x) return true;

    //Recursive Call
    bool reamainingPart = linsearch(arr+1,size-1,x);
    return reamainingPart; 
}

bool binsearch(int *arr,int s,int e,int k){
    int mid = s+(e-s)/2;
    //Base Case
    if(s>e) return false;
    if(arr[mid] == k) return true;

    //Recursive Call
    if(arr[mid] < k) return binsearch(arr,mid+1,e,k);
    else return binsearch(arr,s,mid-1,k);
}

int main(){
    cout<<"Enter length of array : ";
    int x;cin>>x;
    cout<<"Key to search: ";
    int key;cin>>key;

    int *arr = new int[x];
    for(int i=0;i<x;i++) cin>>arr[i];

    bool ans = isSorted(arr,x);
    if(ans) cout<<"Array is sorted."<<endl;
    else cout<<"Array is not sorted."<<endl;

    cout<<"Sum of array is "<<sumArr(arr,x)<<endl;

    bool ans2 = linsearch(arr,x,key);
    bool ans3 = binsearch(arr,0,x,key);
    if(ans2 && ans) cout<<"Element is present in array."<<endl;
    else cout<<"Element is not present in array."<<endl;
    delete arr;
    return 0;
}

