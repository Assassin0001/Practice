#include <iostream>
using namespace std;

int uniqArr(int* ,int);

int main(){
  int arr[100];
  int size;
  cout<<"Enter size of array: ";
  cin>>size; 
  cout<<"Enter elemets of array: ";
  for(int i=0;i<size;i++){
    cin>>arr[i];        
    } 
  cout<<"Unique element is "<<uniqArr(arr,size);
  return 0;
}

int uniqArr(int arr[] ,int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}
