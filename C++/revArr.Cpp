#include <iostream>
using namespace std;

void revArr(int* ,int);
void printArr(int* ,int);

int main(){
  int arr[100];
  int size;
  cout<<"Enter size of array: ";
  cin>>size; 
  cout<<"Enter elemets of array: ";
  for(int i=0;i<size;i++){
    cin>>arr[i];        
    } 
  revArr(arr,size);
  printArr(arr,size);
  return 0;
}

void revArr(int arr[] ,int size){
    int temp=0;
    for(int i=0;i<size/2;i++){
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;        
    }
}
void printArr(int arr[] ,int size){
    cout<<"Reversed Array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";        
    }
}
