bool isPossible(vector <int> arr,int n,int k ,int mid){
    long long painterCount =1;
    long long lengthSum=0;
    for(int i=0; i<n; i++) {
      if( lengthSum + arr[i] <= mid)
      {
         lengthSum += arr[i];
      }
      else
       {
         painterCount++;
         if( painterCount > k || arr[i] > mid) {
             return false;
         }
         lengthSum = arr[i];
      }
    }
     return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    int ans;
    int n = boards.size();
    for(int i=0;i<n;i++){
        sum+=boards[i];
    }
    long long e=sum;
    long long mid =s +(e-s)/2;
    while(s<=e){
        if(isPossible(boards,n,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid =s+(e-s)/2;
    }
    return ans;
}