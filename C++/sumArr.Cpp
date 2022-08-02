#include <iostream>
using namespace std;

int printArr(int* , int);

int main(){
  int arr[100];
  int size;
  cout<<"Enter size of Array: ";
  cin>>size;
  cout<<"Enter elements of array :";
  for(int i=1;i<=size;i++){
      cin>>arr[i];
  }
  cout<<printArr(arr,size);
  return 0;
}

int printArr(int arr[],int size){
    int sum=0;
    cout<<"Array is: ";
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
      sum+=arr[i];
  }
  cout<<endl<<"Sum of elements is: ";
  return sum;
}
