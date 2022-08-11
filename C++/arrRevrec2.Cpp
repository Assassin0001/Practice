#include<iostream>
using namespace std;

void printArr(int*,int);
void revArr(int*,int,int);

int main(){
    int arr[5] ={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    printArr(arr,n);
    cout<<"Reversed array is :-";
    revArr(arr,0,n);
    printArr(arr,n);

}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void revArr(int arr[],int i,int n){
    if(i >=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    revArr(arr,i+1,n);
}

    