class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1){
                ans = i+1;
            }
        }
        return ans;
    }
};

//Optimized Solution

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};