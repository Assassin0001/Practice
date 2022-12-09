#include <bits/stdc++.h>
using namespace std;

long long int sqrtInt(int key){
    int start = 0;
    int end = key;
    long long int ans;
    long long int mid = start+(end-start)/2;    
    while(start<=end){        
          if(mid*mid == key) return mid;
          if(mid*mid > key) end=mid-1;
          else{
            ans=mid;
            start=mid+1;
          }
          mid = start+(end-start)/2;
     }
     return ans;
 }

double morePrecision(int n,int precision,int tempsol){
    double factor = 1;
    double ans = tempsol;

    for(int i=0;i<precision;i++){
        factor = factor/10;

        for(double j=ans ;j*j<n; j=j+factor){
             ans = j;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int tempsol=sqrtInt(n);

    cout<<"Square Root of N is: "<<morePrecision(n,3,tempsol);
}