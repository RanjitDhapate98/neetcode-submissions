class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]){
            i++;
        }
        solve(i+1,nums,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,nums,temp,ans);
        return ans;
    }
};
