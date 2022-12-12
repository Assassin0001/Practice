#include <bits/stdc++.h> 

bool isPossible(vector <int> arr,long long n,long long m ,long long mid){
    long long studentCount =1;
    long long pageSum=0;
    for(int i=0; i<n; i++) {
      if( pageSum + arr[i] <= mid)
      {
         pageSum += arr[i];
      }
      else
       {
         studentCount++;
         if( studentCount > m || arr[i] > mid) {
             return false;
         }
         pageSum = arr[i];
      }
    }
     return true;
}

long long ayushGivesNinjatest(int m, int n, vector<int> arr) 
{	
    long long s=0;
    long long sum=0;
    long long ans;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    long long e=sum;
    long long mid =s +(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1; // because we have to find minimum of max allocated time.
        }
        else{
            s=mid+1;
        }
        mid =s+(e-s)/2;
    }
    return ans;
}