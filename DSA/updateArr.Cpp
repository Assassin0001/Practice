#include <iostream>
using namespace std;

void updateArr(int*);
void printArr(int* , int);

int main(){
  int arr[100];
  int size;
  cout<<"Enter size of Array: ";
  cin>>size;
  cout<<"Enter elements of array :";
  for(int i=1;i<=size;i++){
      cin>>arr[i];
  }
  updateArr(arr);
  printArr(arr,size);
  return 0;
}

void updateArr(int arr[]){
  int size;
  cout<<"Enter updated size of Array: ";
  cin>>size;
  cout<<"Enter elements of array :";
  for(int i=1;i<=size;i++){
      cin>>arr[i];
  }
}

void printArr(int arr[],int size){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
  }
}
