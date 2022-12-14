#include<iostream>
using namespace std;

void printArr(int*,int);
void revArr(int*,int,int);

int main(){
    int arr[10] ={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    printArr(arr,n);
    cout<<"Reversed array is :-";
    revArr(arr,0,n-1);
    printArr(arr,n);

}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void revArr(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    revArr(arr,l+1,r-1);
}

    