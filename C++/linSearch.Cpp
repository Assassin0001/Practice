#include <iostream>
using namespace std;

bool search(int* ,int,int);
void printArr(int*,int);

int main(){
  int arr[]={1,2,3,5,7,11,13,15,17,19};
  int key;
  cout<<"Enter key: ";
  cin>>key;  
  int size=sizeof(arr)/sizeof(int);
  if(search(arr,key,size))
    cout<<key<<" is present.";
  else
    cout<<key<<" is not present.";
  printArr(arr,size);
  return 0;
}

bool search(int arr[],int key,int size){
    for(int i=0;i<size;i++){
        if(key==arr[i]){
            return true;
        }
    }
    return false;
}

void printArr(int arr[],int size){
    cout<<endl<<"Array is : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
