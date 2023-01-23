#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    //Check for n-1 Rounds max 
    for(int i=1;i<n;i++){
        bool swapped =false;
        for(int j=0;j<n-i;j++){
            //Check if next element is greater
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        // Check if array is already sorted
        if(swapped == false) break;
    }
}