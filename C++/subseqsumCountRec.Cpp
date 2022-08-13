#include<iostream>
#include<vector>
using namespace std;

int printS(int ind,int s,int sum,int arr[],int n){
    // condition not satisfied
    // strictly only when positives only in array. 
    if(s>sum) return 0;
    if(ind==n){
        // checking if index reached last positition
        if(s == sum){
            //checking sum
         return 1;
         }
        return 0;
        }
        // pick 

    s+=arr[ind];
    int l= printS(ind+1,s,sum,arr,n);
      // not pick

    s-=arr[ind];
    int r = printS(ind+1,s,sum,arr,n);
    return l+r;
    }   

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    cout<<printS(0,0,sum,arr,n);
}

 
