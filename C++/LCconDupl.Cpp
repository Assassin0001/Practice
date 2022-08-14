class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int flag = 0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int  i=0;i<size-1;i++){
                if(nums[i+1]==nums[i]){
                    flag = 1;
                    return true;
                    break;
            }
        }
        return false;
    }
};