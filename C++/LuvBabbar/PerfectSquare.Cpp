class Solution {
public:
bool binSearch(int key){
    int start = 0;
    int end = key;
    bool ans = false;
    long long int mid = start+(end-start)/2;    
    while(start<=end){        
          if(mid*mid == key){
            ans=true;
            return mid;
          }
          if(mid*mid > key) end=mid-1;
          else{
            start=mid+1;
          }
          mid = start+(end-start)/2;
     }
     return ans;
 }
    bool isPerfectSquare(int num) {
        return binSearch(num);
    }
};