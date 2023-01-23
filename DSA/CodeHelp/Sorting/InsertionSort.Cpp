#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    ///Check for Rounds
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j=i-1;
        //Check behind if any min number is there 
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}