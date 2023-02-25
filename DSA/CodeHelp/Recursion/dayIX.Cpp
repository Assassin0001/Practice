//Bactrack Approach
class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int> nums,int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=index; j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(ans,nums,index+1);
            //Backtrack
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,nums,0);
        return ans;
    }
};