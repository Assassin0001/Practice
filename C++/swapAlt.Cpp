#include <iostream>
using namespace std;

void swapAlt(int* ,int);
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
  swapAlt(arr,size);
  printArr(arr,size);
  return 0;
}

void swapAlt(int arr[] ,int size){
    for(int i=0;i<size;i=i+2){
        if(i+1<size){
        swap(arr[i],arr[i+1]);
        } 
    }
}
void printArr(int arr[] ,int size){
    cout<<"Alternate Swapped Array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";        
    }
}
