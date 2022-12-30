class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        set<int>s(nums.begin(),nums.end());//creating set bcz unique elements are required

        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-diff)!=s.end() && s.find(nums[i]-2*diff)!=s.end()){
                ans++;
            }
        }
        return ans;      
    }
};