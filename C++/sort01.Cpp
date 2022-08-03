#include <iostream>
using namespace std;

void printArr(int* ,int);
void sort01(int* ,int);

int main(){
  int arr[50];
  int size;
  cout<<"Enter size of array: ";
  cin>>size;
  cout<<"Enter elements of Array: ";
  for(int i =0;i<size;i++){
    cin>>arr[i];
  }
  sort01(arr,size);
  printArr(arr,size);
  return 0;
}

void sort01(int arr[] ,int size){
    int left =0;
    int right =size-1;
    while(left < right){

        if(arr[left]==0){
            left++;
        }
        else if(arr[right]==1){
            right--;
        }
        // if reached here , it means :
        // arr[left]==1 and arr[right]==0
        else{
         swap(arr[left],arr[right]);
         left++;
         right--;
        }
    }
}

void printArr(int arr[] ,int size){
    cout<<"Sorted Array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";        
    }
}
