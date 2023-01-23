//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long merge(long long arr[],long long temp[],long long int s,long long int mid,long long int e){
        
        long long int inv_count = 0;
        long long int i,j,k;
        i = s;
        j = mid;
        k = s;
        
        while((i <= mid-1) && (j <= e)){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                inv_count = inv_count + (mid-i);
            }
        }    
            
        while(i <= mid-1)
                temp[k++] = arr[i++];

        while(j <= e)
                temp[k++] = arr[j++];

        for(i=s;i<=e;i++)
            arr[i] = temp[i];
            
        return inv_count;
    }
  
    long long int merge_Sort(long long arr[],long long temp[],long long s,long long e){
        long long mid = s + (e-s)/2;
        long long int inv_count = 0;
        if(e > s){
            inv_count += merge_Sort(arr,temp,s,mid);
            inv_count += merge_Sort(arr,temp,mid+1,e);
            
            inv_count += merge(arr,temp,s,mid+1,e);
        }
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return merge_Sort(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends