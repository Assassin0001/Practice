#include<iostream>
#include<vector>
using namespace std;

bool printS(int ind,vector<int> &ds,int s,int sum,int arr[],int n){
    if(ind==n){
        // checking if index reached last positition
        if(s == sum){
            //checking sum
         for(auto it: ds) cout<<it<<" ";
         cout<<endl;
         return true;
         }
        return false;
        }
        // pick 
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printS(ind+1,ds,s,sum,arr,n)== true) return true;
      // not pick
    ds.pop_back();
    s-=arr[ind];
    if(printS(ind+1,ds,s,sum,arr,n)== true) return true;
    return false;
    }   

int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
}

 
