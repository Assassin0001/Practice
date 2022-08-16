#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    void func(int ind ,int s,int N,vector<int> &arr,vector<int> &sumSubset){
        if(ind == N){
            sumSubset.push_back(s);
            return;
        }
        //picking the index
        func(ind+1,s+arr[ind],N,arr,sumSubset);
        //not picking the index
        func(ind+1,s,N,arr,sumSubset);
    } 
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
     vector <int> sumSubset;
     func(0,0,N,arr,sumSubset);
     sort(sumSubset.begin(),sumSubset.end());
     return sumSubset;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends