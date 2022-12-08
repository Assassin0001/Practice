//Brute Force Approach
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num;
        for(int i=0;i<nums.size();i++){
            if(count(nums.begin(),nums.end(),nums[i]) == 1)
               num=nums[i];
        }
        return num;
    }
};

// XOR Approach
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num;
        for(auto x:nums){
            num^=x;
        }
        return num;
    }
};


