// Merge Sort
#include<bits/stdc++.h>
using namespace std;

void merge(int* arr,int s,int e){
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrIndex = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[mainArrIndex++];
    }

    mainArrIndex = mid+1; 
    for(int i=0;i<len2;i++){
        second[i] = arr[mainArrIndex++];
    }

    //Merge arrays
    int index1 = 0;
    int index2 = 0;
    mainArrIndex = s;

    while(index1 < len1 && index2< len2){
        if(first[index1] < second[index2]) arr[mainArrIndex++] = first[index1++];
        else arr[mainArrIndex++] = second[index2++];
    }
    while(index1 < len1){
        arr[mainArrIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr,int s,int e){
    int mid = s+(e-s)/2;
    
    //Base Case
    if(s>=e) return;

    //Right part sort kro
    mergeSort(arr,s,mid);
    
    //Left part sort kro
    mergeSort(arr,mid+1,e);

    //Merge
    merge(arr,s,e);
}

int main(){
    int arr[5] = {1,3,4,2,5};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}