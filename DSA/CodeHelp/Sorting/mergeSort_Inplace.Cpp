// Merge Sort In-Place
// T.C. O(n2*logn)
#include<bits/stdc++.h>
using namespace std;

void merge(int* arr,int start,int mid,int end){
    int start2 = mid+1;

    //Array is already sorted
    if(arr[mid] <= arr[start2]) return;
    
    //Merge arrays
    while(start <= mid && start2 <= end){
        if(arr[start] <= arr[start2]) start++;
        else{
            int value = arr[start2];
            int index = start2;

            //Shift all elements between start1 & start2 *Right* by 1
            while(index != start){
                arr[index] = arr[index-1];
                index--;
            }
            arr[index] = value;

            //Update Pointers
            start++;
            mid++; // ??
            start2++;
        }
    }
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
    merge(arr,s,mid,e);
}

int main(){
    int arr[6] = {1,3,4,2,5,5};
    int n=6;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}