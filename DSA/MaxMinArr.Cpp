#include <iostream>
#include <climits>

using namespace std;

int getMax(int* ,int);
int getMin(int* ,int);

int main(){
    int arr[100];
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter elements of array: "<<endl;
    for(int i=1;i<=size;i++){
           cin>>arr[i];
    }
    cout<<"Maximum no. is "<<getMax(arr,size)<<endl;
    cout<<"Minimum no. is "<<getMin(arr,size);
    return 0;
}

int getMax(int arr[],int size){
    int maxi = INT_MIN;
    for(int i=1;i<=size;i++){
        maxi=max(maxi,arr[i]);
        //if(arr[i]>max){
        //    max=arr[i];
        //}
    }
    return maxi;
   
}

int getMin(int arr[],int size){
    int mini = INT_MAX;
    for(int i=1;i<=size;i++){
        //if(arr[i]<min){
            mini=min(mini,arr[i]);
        //   min=arr[i];}
    }
    return mini;
   
}